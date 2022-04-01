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
            break;
    }
}
