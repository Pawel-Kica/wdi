void selectionSort(float arr[], int length)
{
    // int length = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < length; i++)
    {
        int idx_of_min = i;

        for (int j = i + 1; j < length; j++)
            if (arr[idx_of_min] > arr[j])
                idx_of_min = j;

        swap(&arr[idx_of_min], &arr[i]);
    }
}
