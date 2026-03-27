#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// malloc count
static uint32_t malloc_count = 0;
static size_t   bytes_alloc = 0;


/* This function will safely allocate memory, so we can replace malloc
    and it will increment our count so we can track if everything is fine*/
void *safe_malloc(size_t bytes_to_allocate){

    void * pointer = malloc(bytes_to_allocate);

    if (pointer == NULL) {
        fprintf(stderr, "Error Allocating memory");
        return NULL;
    }
    malloc_count++;
    bytes_alloc += bytes_to_allocate;

    return pointer;
}

/*This function will safely realloc by chekcing null and incrementing our count*/
void *safe_realloc(void * dest_pointer , size_t bytes_to_reallocate, size_t old_size){

    if (dest_pointer == NULL) {
        return safe_malloc(bytes_to_reallocate);
    }

    void * pointer = realloc(dest_pointer, bytes_to_reallocate);

     if (pointer == NULL) {
        fprintf(stderr, "Error Reallocating memory");
        return NULL;
    }
    
    if (bytes_to_reallocate >= old_size) {
        bytes_alloc += (bytes_to_reallocate - old_size);
    } else {
        bytes_alloc -= (old_size - bytes_to_reallocate);
    }

    return pointer;
}

/* Safe free avoid the redudancy of null checkers and decrement our counter*/
void safe_free(void * pointer, size_t free_size_bytes){

    if (pointer ==  NULL) {
        return;
    }

    free(pointer);
    bytes_alloc -= free_size_bytes;
    malloc_count--;
}

/* This function is for us to print the status of the dynamic memory allocated*/
void print_memory_stats(void) {
    printf("=== Memory Stats ===\n");
    printf("Active allocations: %u\n", malloc_count);
    printf("Active bytes:       %zu\n", bytes_alloc);
    printf("====================\n");
}
