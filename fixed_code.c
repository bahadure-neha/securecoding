#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command-line argument
    if (argc != 2) { 
        fprintf(stderr, "Error: Please provide the address of a file as an input.\n");
        return -1;
    }

    struct stat fileStat;

    // Get file metadata
    if (stat(argv[1], &fileStat) != 0) {
        perror("Error: Unable to access the file");
        return -1;
    }

    // Print file size in bytes
    printf("%lld\n", (long long)fileStat.st_size);
    
    return 0;
}
