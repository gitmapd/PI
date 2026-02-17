#include <stdio.h>
#include <stdint.h>

// 1. Define the "Package" struct
typedef struct {
    uint32_t *data; // Pointer to the numbers
    int total;      // The size we "remember"
} DecimalList;

// --- THE WRONG WAY ---
void the_wrong_way(uint32_t *array) {
    // Inside a function, 'array' is just a pointer.
    // sizeof(array) will be 8 (on 64-bit systems)
    // sizeof(array[0]) will be 4 (for uint32_t)
    int count = sizeof(array) / sizeof(array[0]);
    
    printf("WRONG WAY: Detected %d elements (because sizeof(ptr) is fixed at 8 bytes).\n", count);
}

// --- THE RIGHT WAY (Using the Struct) ---
void the_right_way(DecimalList list) {
    // We don't calculate the size here; we just read the 'total' we saved earlier.
    printf("RIGHT WAY: Detected %d elements (read from the struct total).\n", list.total);
    
    printf("Data inside: ");
    for (int i = 0; i < list.total; i++) {
        printf("%u ", list.data[i]);
    }
    printf("\n");
}

int main() {
    // An array of 6 numbers
    uint32_t raw_numbers[] = {10, 13, 25, 57, 125, 1964};

    // 2. Initialize the struct
    DecimalList my_list;
    my_list.data = raw_numbers;
    
    // We calculate the size HERE where the array is "alive"
    my_list.total = sizeof(raw_numbers) / sizeof(raw_numbers[0]);

    printf("--- SCOPE: main() ---\n");
    printf("Actual elements in raw_numbers: %d\n\n", my_list.total);

    printf("--- SCOPE: Inside Functions ---\n");
    
    // Pass just the pointer (will fail to detect size)
    the_wrong_way(raw_numbers); 

    // Pass the struct (will correctly show 6)
    the_right_way(my_list);

    return 0;
}