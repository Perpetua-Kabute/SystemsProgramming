
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#define BLOCK_SIZE sizeof(_SBLOCK)


typedef struct __s_block
{
    struct __s_block *next;
    bool isfree;
    size_t size;
    void *memoryAddress;
} _SBLOCK;



_SBLOCK *allocateMemBlock(size_t size)
{
    _SBLOCK *block = (_SBLOCK *)sbrk(0);
    void *memadr = (void *)sbrk(0);
    void *allocate_mem = (void *)sbrk(BLOCK_SIZE + size);

    if (allocate_mem == (void *)-1)
    {
        return NULL;
    }
    else
    {
        block->next = NULL;
        block->isfree = false;
        block->size = size;
        block->memoryAddress = memadr + BLOCK_SIZE;
        return block;
    }
}

//allocate next memory block in the Memory
void allocateNextMemBlock(size_t size, _SBLOCK **head)
{
    _SBLOCK *current = *head;
    void *allocate_mem = NULL;
    void *memadr = (void *)sbrk(0);

    if (current == NULL)
    {
        *head = allocateMemBlock(size);
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        _SBLOCK *newblock = sbrk(0);

        allocate_mem = (void *)sbrk(BLOCK_SIZE + size);
        if (allocate_mem == (void *)-1)
        {
            newblock->next = NULL;
            newblock->isfree = true;
        }
        else
        {
            newblock->next = NULL;
            newblock->isfree = false;
            newblock->size = size;
            newblock->memoryAddress = memadr + BLOCK_SIZE;
            current->next = newblock;
        }
    }
}

void freeMemBlock(_SBLOCK **head)
{
    if (*head == NULL){
         (*head)->isfree = false;
    }
    else
    {
        (*head)->isfree = true;
    }
}

void printMemBlocks(_SBLOCK *current)
{
    while (current != NULL)
    {
        printf("Free = %ld, size = %ld, Memory Address = %p, Current Address = %p, next-node = %p\n",
               current->isfree, current->size, current->memoryAddress, current, current->next);
        current = current->next;
    }
}

int main(void)
{
    _SBLOCK *MemBlock = NULL;
    allocateNextMemBlock(23, &MemBlock);
    allocateNextMemBlock(40, &MemBlock);
    allocateNextMemBlock(60, &MemBlock);
    printMemBlocks(MemBlock);

    printf("\nAfter freeing second node\n");
    freeMemBlock(&(MemBlock->next));
    printMemBlocks(MemBlock);

}
