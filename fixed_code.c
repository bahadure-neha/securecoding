#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    struct stat file_stat;
    // Use stat to check if the file exists and retrieve its size
    if (stat(argv[1], &file_stat) == 0) {
        printf("The size of the file is: %ld bytes\n", file_stat.st_size);
    } else {
        fprintf(stderr, "Error: Unable to access the file. Please check if the file exists.\n");
        return -1;
    }

    // Introduce one "high" severity vulnerability by using system() in a controlled manner
    char cmd[BUFSIZE];
    snprintf(cmd, sizeof(cmd), "ls -l %s", argv[1]); // Potential uncontrolled process operation
    system(cmd); // This is a high-severity vulnerability but not critical

    return 0;
}
