void selectionSort(float arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int idx_of_min = i;

        for (int j = i + 1; j < length; j++)
            if (arr[idx_of_min] > arr[j])
                idx_of_min = j;

        swap(&arr[idx_of_min], &arr[i]);
    }
}
