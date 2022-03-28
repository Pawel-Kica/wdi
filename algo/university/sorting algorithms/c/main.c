#include <stdio.h>
#include <stdbool.h>
#include "helpers.c"
#include "bubbleSort.c"
#include "selectionSort.c"
#include "insertionSort.c"
#include "mergeSort.c"

int main()
{
    float arr[] = {-5.22, 5.27, -12.2002, -5.224, 3.2004};
    int length = sizeof(arr) / sizeof(arr[0]);

    // int length;
    // printf("Length: ");
    // scanf("%d", &length);
    // float arr[length];
    // printf("Elements (float): \n", length);
    // for (int i = 0; i < length; ++i)
    // {
    //     scanf("%f", &arr[i]);
    // }

    printf("\n");

    printf("Sorting with bubbleSort\n");
    decorator(&bubbleSort, arr, length);

    printf("Sorting with selectionSort\n");
    decorator(&selectionSort, arr, length);

    printf("Sorting with insertionSort\n");
    decorator(&insertionSort, arr, length);

    printf("Sorting with mergeSort\n");
    decorator(&mergeSort, arr, length);

    return 0;
}