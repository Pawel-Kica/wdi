#include <stdio.h>

void insertionSort(float arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 & key < arr[j])
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
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

    insertionSort(arr, length);

    printf("After: ");
    printArray(arr, length);
    return 0;
}