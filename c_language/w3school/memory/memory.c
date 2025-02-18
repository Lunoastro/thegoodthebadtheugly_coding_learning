#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    ptr = (int *)malloc(5 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        printf("Memory successfully allocated using malloc.\n");
        free(ptr);
        printf("Memory successfully deallocated using free.\n");
    }
    return 0;
}