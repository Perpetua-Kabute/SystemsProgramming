
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct __s_block
{
    struct __s_block *next;
    bool isfree;
    size_t size;
    void *memoryAddress;
} _SBLOCK;

#define BLOCK_SIZE sizeof(_SBLOCK)

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

//allocate next memory block
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
    if (*head == NULL)
    {
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
        printf("isfree = %ld, size = %ld, memoryAddress = %p, current = %p, next-node = %p\n",
               current->isfree, current->size, current->memoryAddress, current, current->next);
        current = current->next;
    }
}

int main()
{
    _SBLOCK *sMemBlock = NULL;
    allocateNextMemBlock(20, &sMemBlock);
    allocateNextMemBlock(36, &sMemBlock);
    allocateNextMemBlock(90, &sMemBlock);
    printMemBlocks(sMemBlock);

    printf("\nAfter freeing second node\n");
    freeMemBlock(&(sMemBlock->next));
    printMemBlocks(sMemBlock);

    return 0;
}
