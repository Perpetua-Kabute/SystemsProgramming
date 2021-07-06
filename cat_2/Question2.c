#include <stdio.h>
#include <stdlib.h>

//  allocates memory for k integers
int main()
{
    int i, n;

    printf("Enter number of integers: \n");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }

    // Get the elements of the array
    for (i = 0; i < n; ++i) {
        ptr[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    printf(\n)

    free(ptr);
}