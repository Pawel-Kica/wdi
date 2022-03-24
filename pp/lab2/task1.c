#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandomNumbers(int arr[], int length, int max, int min)
{
    for (int i = 0; i < length; i++)
        arr[i] = (rand() % max) + min;
}

void reverse(int arr[], int length)
{
    int temp = 0;
    for (int i = 0; i < length / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}

void printArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    srand(time(NULL));
    int t1[10];
    int t2[15];
    fillRandomNumbers(t1, 10, 10, 1);
    fillRandomNumbers(t2, 20, 10, 1);
    printArr(t1, 10);
    printArr(t2, 15);
    reverse(t1, 10);
    printArr(t1, 10);

    return 0;
}