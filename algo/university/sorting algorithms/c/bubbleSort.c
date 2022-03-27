#include <stdio.h>
#include <stdbool.h>

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(float arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

void bubbleSort(float arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < length - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSorted = false;
            }
        if (isSorted)
        {
            break;
        }
    }
}

int main()
{
    // float arr[] = {-5.22, 5.27, -12.2002, -5.224, 9.2004};
    // int length = sizeof(arr) / sizeof(arr[0]);

    int length;
    printf("Length: ");
    scanf("%d", &length);

    float arr[length];
    printf("Elements (float): \n", length);
    for (int i = 0; i < length; ++i)
    {
        scanf("%f", &arr[i]);
    }

    printf("Before: ");
    printArray(arr, length);
    bubbleSort(arr, length);
    printf("After: ");
    printArray(arr, length);
    return 0;
}