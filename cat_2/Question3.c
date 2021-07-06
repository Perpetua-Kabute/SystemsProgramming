#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, *sum = 0, *ptr;
    float *standard_deviation, variance;
    
    printf("Enter the number of integers :\n");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    sum = (int *)malloc(sizeof(int));

    standard_deviation = (float *)malloc(sizeof(float));

    printf("Enter %d elements \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    for (int i = 0; i < n; i++)
    {
        *sum += *(ptr + i);
    }

    float mean = *sum / (float)n;

    for (int i = 0; i < n; i++)
    {
        variance += pow(*(ptr + i) - mean, 2);
    }

    *standard_deviation = sqrt(variance / (float)n);

    printf("Sum = %d\n", *sum);
    printf("Mean = %f\n", mean);
    printf("Standard Deviation = %f\n", *standard_deviation);

    free(ptr);
    free(standard_deviation);
    free(sum);

    return 0;
}