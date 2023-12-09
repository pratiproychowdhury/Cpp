#include <cstdio>
#include <cstdint>

#include "emb2.h"

/*
 * Story EMB-2
 * -----------
 *
 * Write a customized memory allocator for allocating blocks of fixed size
 * the allocator will be initialized with a memory chunk, the size of the chunk and the
 * individual block size.
 *
 * As additional requirement the class must not use a different memory allocator.
 *
 * the allocator needs to provide the following methods
 * - intialize with raw memory, size and block size
 * - allocate a block
 * - free a block
 * - return number of allocated blocks
 * - return number of total blocks
 */
 
 
BlockAllocator::BlockAllocator(void* memory, size_t total_size, size_t block_size) {
    allocator = new BlockData();
    allocator->mem_start = memory;
    allocator->total_size = total_size;
    allocator->block_size = block_size;
    allocator->allocated_blocks = 0;

    // not clearing out the memory since we would need cstring header
    // memset(memory, 0, total_size);

    int numPages = total_size / block_size;

    // Bit in position n in vector indicates if page #n is in use
    allocator->page_list = new char[numPages];
}

BlockAllocator::~BlockAllocator() {

    // free(allocator->page_list);
    delete[] allocator->page_list;
}

void* BlockAllocator::allocateBlock() {

    // Check if all available memory is already allocated
    if (allocator->allocated_blocks == totalBlocks())
        return NULL;

    // Scan page list until first free page is found
    for (int i=0; i<totalBlocks(); i++) {
        if ( !allocator->page_list[i] ) {
            allocator->page_list[i] = 1;
            allocator->allocated_blocks++;
            return (char *)allocator->mem_start + i*allocator->block_size;
        }
    }

    return NULL;
}

void BlockAllocator::freeBlock(void* block) {

    int blockNum = ((char *)block - (char *)allocator->mem_start) / allocator->block_size;

    // Protect against freeing an unallocated block
    if (allocator->page_list[blockNum]) {
        allocator->page_list[blockNum] = 0;
        // memset(block, 0, allocator->block_size);
        allocator->allocated_blocks--;
    }
}

size_t BlockAllocator::allocatedBlocks() {
    return allocator->allocated_blocks;
}

size_t BlockAllocator::totalBlocks() {
    return allocator->total_size / allocator->block_size;
}

// Provide a sample utilizing the allocator above
// the program should be able to run and provide sensible test output using stdio
int main(int argc, char *argv[])
{
    size_t mem_size = 8192;
    size_t block_size = 1024;
    void* memblock = new char[mem_size];

    BlockAllocator testAllocator(memblock, mem_size, block_size);

    printf("Memory position of allocated mem chunk: %p\n", memblock);

    void* newMem1 = testAllocator.allocateBlock();
    void* newMem2 = testAllocator.allocateBlock();

    printf("Memory positions of first 2 allocated blocks: %p and %p\n", newMem1, newMem2);
    printf("Memory blocks allocated: %lu\n", testAllocator.allocatedBlocks());

    testAllocator.freeBlock(newMem1);
    printf("Memory blocks allocated: %lu\n", testAllocator.allocatedBlocks());
}
