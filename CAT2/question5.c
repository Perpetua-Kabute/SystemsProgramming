#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, *sum = 0, *ptr;
    float *standard_deviation, variance;
    
    printf("Enter the number of elements :\n");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));

    sum = (int *)calloc(1, sizeof(int));

    standard_deviation = (float *)calloc(1, sizeof(float));

    printf("Enter %d integers \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    //adding the number of integers to add
    printf("Enter the number of integers to be added: \n");
    scanf("%d", &k);

    // change the size allocated to the pointer using realloc
    ptr = (int *)realloc(ptr, (n + k) * sizeof(int));

    printf("Enter %d more integers \n", k);

    //read the input
    for (int i = n; i < n + k; i++)
    {
        scanf("%d", ptr + i);
    }

    //sum
    for (int i = 0; i < n + k; i++)
    {
        *sum += *(ptr + i);
    }

    //mean
    float mean = *sum / (float)n + k;

    //variance
    for (int i = 0; i < n; i++)
    {
        variance += pow(*(ptr + i) - mean, 2);
    }

    //standard deviation
    *standard_deviation = sqrt(variance / (float)n);

    printf("Sum = %d\n", *sum);
    printf("Mean = %f\n", mean);
    printf("Standard Deviation = %f\n", *standard_deviation);

    free(ptr);
    free(standard_deviation);
    free(sum);

    return 0;
}