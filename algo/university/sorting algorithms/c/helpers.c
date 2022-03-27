void printArray(float arr[], int length)
{
    // int length = sizeof(arr) / sizeof(arr[0]);
    int i;
    for (i = 0; i < length; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void copyArray(float arr[], float copy[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        copy[i] = arr[i];
    }
}

int compare(const void *a, const void *b)
{
    return (*(float *)a >= *(float *)b) ? 1 : -1;
}

void decorator(void (*f)(), float arr[], int length)
{
    float copy[length];
    float secondCopy[length];

    copyArray(arr, copy, length);

    // copyArray(arr, secondCopy, length);
    // qsort(secondCopy, length, sizeof(float), compare);

    printf("Before: ");
    printArray(copy, length);
    f(copy, length);
    printf("After: ");
    printArray(copy, length);
    printf("\n");
}