void mergeSort(float arr[], int length)
{
    // printArray(arr, length);

    if (length > 1)
    {
        int arr1_len = length / 2;
        int arr2_len;

        if (length % 2 != 0)
            arr2_len = arr1_len + 1;

        float arr1[arr1_len], arr2[arr1_len];

        for (int i = 0; i < arr1_len; i++)
            arr1[i] = arr[i];

        for (int j = 0; j < arr2_len; j++)
            arr2[j] = arr[arr1_len + j];

        mergeSort(arr1, arr1_len);
        mergeSort(arr2, arr2_len);

        int arr_idx = 0;
        int arr1_idx = 0;
        int arr2_idx = 0;

        while (arr1_idx < arr1_len && arr2_idx < arr2_len)
        {
            if (arr1[arr1_idx] < arr2[arr2_idx])
            {
                arr[arr_idx] = arr1[arr1_idx];
                arr1_idx += 1;
            }
            else
            {
                arr[arr_idx] = arr2[arr2_idx];
                arr2_idx += 1;
            }

            arr_idx += 1;
        }

        while (arr1_idx < arr1_len)
        {
            arr[arr_idx] = arr1[arr1_idx];
            arr1_idx += 1;
            arr_idx += 1;
        }

        while (arr2_idx < arr2_len)
        {

            arr[arr_idx] = arr2[arr2_idx];
            arr2_idx += 1;
            arr_idx += 1;
        }
    }
    printArray(arr, length);
}