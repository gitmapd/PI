#include <stdio.h>
#include <stdlib.h> // Required for malloc and free
#include <stdint.h>

typedef struct {
    uint32_t *data;
    int total;
} DataList;

// Function to create and allocate a list
void initList(DataList *list, int size) {
    list->total = size;
    // Allocate memory: (number of elements) * (size of one element)
    list->data = (uint32_t *)malloc(size * sizeof(uint32_t));

    // Safety check: always ensure malloc didn't fail
    if (list->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Function to clean up the memory
void freeList(DataList *list) {
    free(list->data);
    list->data = NULL; // Good practice to avoid "dangling pointers"
    list->total = 0;
}

int main() {
    DataList myList;

    // Create a list for 5 numbers
    initList(&myList, 5);

    // Fill it with some data
    for (int i = 0; i < myList.total; i++) {
        myList.data[i] = i * 10;
    }

    // ... use the list ...

    // IMPORTANT: Clean up before the program ends
    freeList(&myList);

    return 0;
}