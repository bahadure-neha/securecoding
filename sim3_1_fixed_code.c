#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please provide an index.\n");
        return 1;
    }

    char *items[] = {"boat", "car", "truck", "train"};
    int index = atoi(argv[1]);

    if (index < 0 || index >= sizeof(items) / sizeof(items[0])) {
        printf("Invalid index.\n");
        return 1;
    }

    printf("You selected %s\n", items[index]);

    return 0;
}
