void insertionSort(float arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
