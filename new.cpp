void merge(vector<int> arr, int l, int mid, int r)
{
    int *arr1 = new int[mid - l + 1];
    int *arr2 = new int[r - mid];
    for (int i = 0; i < mid - l + 1; i++)
        arr1[i] = arr[l + i];
    for (int j = 0; j < r - mid; j++)
        arr2[j] = arr[j + mid + 1];
    int *result = new int[r - l + 1];
    int i = 0, j = 0, k = 0;
    while (i < mid - l + 1 && j < r - mid)
    {
        if (arr1[i] <= arr2[j])
        {
            result[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            result[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < mid - l + 1)
    {
        result[k] = arr1[i];
        i++;
        k++;
    }
    while (j < r - mid)
    {
        result[k] = arr2[j];
        j++;
        k++;
    }
    for (int i = 0; i < r - l + 1; i++)
        arr[i] = result[i];
}
void mergeSort(vector<int> &arr, int l, int r)
{
    // Write Your Code Here
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}