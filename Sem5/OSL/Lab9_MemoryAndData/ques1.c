#include <stdio.h>
#include <stdlib.h>

struct MemoryBlock {
    int block_size;
    int allocated;
    struct MemoryBlock* next;
};

struct MemoryBlock* createBlock(int size) {
    struct MemoryBlock* block = (struct MemoryBlock*)malloc(sizeof(struct MemoryBlock));
    block->block_size = size;
    block->allocated = 0;
    block->next = NULL;
    return block;
}

struct MemoryBlock* firstFit(struct MemoryBlock* memory, int size) {
    struct MemoryBlock* current = memory;
    while (current != NULL) {
        if (current->allocated == 0 && current->block_size >= size) {
            current->allocated = 1;
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

struct MemoryBlock* bestFit(struct MemoryBlock* memory, int size) {
    struct MemoryBlock* current = memory;
    struct MemoryBlock* bestFitBlock = NULL;

    while (current != NULL) {
        if (current->allocated == 0 && current->block_size >= size) {
            if (bestFitBlock == NULL || current->block_size < bestFitBlock->block_size) {
                bestFitBlock = current;
            }
        }
        current = current->next;
    }

    if (bestFitBlock != NULL) {
        bestFitBlock->allocated = 1;
    }

    return bestFitBlock;
}

void deallocate(struct MemoryBlock* block) {
    if (block != NULL) {
        block->allocated = 0;
    }
}

void printMemory(struct MemoryBlock* memory) {
    struct MemoryBlock* current = memory;
    while (current != NULL) {
        printf("Block Size: %d, Allocated: %d\n", current->block_size, current->allocated);
        current = current->next;
    }
}

int main() {
    struct MemoryBlock* memory = createBlock(100); 

    struct MemoryBlock* block1 = firstFit(memory, 30);
    struct MemoryBlock* block2 = firstFit(memory, 20);

    printf("First Fit Allocation:\n");
    printMemory(memory);

    deallocate(block1);
    deallocate(block2);

    printf("\nAfter Deallocation:\n");
    printMemory(memory);

    struct MemoryBlock* block3 = bestFit(memory, 35);
    struct MemoryBlock* block4 = bestFit(memory, 25);

    printf("\nBest Fit Allocation:\n");
    printMemory(memory);

    deallocate(block3);
    deallocate(block4);

    printf("\nAfter Deallocation:\n");
    printMemory(memory);

    free(memory); 

    return 0;
}
