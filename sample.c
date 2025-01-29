#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *items[] = {"boat", "car", "truck", "train"};
    int index = atoi(argv[1]);
    printf("You selected %s\n", items[index]);
}
