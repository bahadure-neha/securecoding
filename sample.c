#include <stdio.h>
int getValueFromArray(int *array, int len, int index) {
    if (index < 0 || index >= len) {  // Bounds checking added
        return -1;  // Return error value for out-of-bounds access
    }
    return array[index];
}
