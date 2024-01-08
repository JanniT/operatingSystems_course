#include <stdlib.h>

int main() {
    // Allocate memory for an array of integers of size 100
    int *data = (int *)malloc(100 * sizeof(int));

    // Access an element beyond the allocated size (out of bounds)
    data[100] = 0;

    // Free the allocated memory
    free(data);

    return 0;
}
