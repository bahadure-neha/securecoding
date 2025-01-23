#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BUFSIZE 256

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return EXIT_FAILURE;
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == 0) {
        printf("The size of the file is: %ld bytes\n", file_stat.st_size);
    } else {
        fprintf(stderr, "Error: Unable to access the file. Please check if the file exists.\n");
        return EXIT_FAILURE;
    }

    // Introducing ONE "high" severity vulnerability
    char cmd[BUFSIZE];
    snprintf(cmd, sizeof(cmd), "/bin/ls -l -- %s", argv[1]); // Controlled command execution
    if (system(cmd) == -1) { // Ensuring the system call is checked
        fprintf(stderr, "Error executing command.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
