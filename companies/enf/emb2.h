#ifndef _EMB2_H
#define _EMB2_H

typedef struct {
    void* mem_start;
    char* page_list;
    size_t total_size;
    size_t block_size;
    size_t allocated_blocks;
} BlockData;

 class BlockAllocator
 {
 public:
     BlockAllocator(void* memory, size_t total_size, size_t block_size);
     ~BlockAllocator();
     void *allocateBlock();
     void freeBlock(void*); 
     size_t allocatedBlocks();
     size_t totalBlocks();

private:
    BlockData* allocator;
 };

 #endif