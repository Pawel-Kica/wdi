#include <stdio.h>

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(float arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < length; j++)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }
        swap(&arr[smallest], &arr[i]);
    }
}

void printArray(float arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%.6f ", arr[i]);
    printf("\n");
}

int main()
{
    float arr[] = {-1.25, 20.134, -12.0404, 25.0202, 15.3030};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    printArray(arr, length);

    selectionSort(arr, length);

    printf("After: ");
    printArray(arr, length);
    return 0;
}