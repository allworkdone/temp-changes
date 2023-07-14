bool areSame(int arr[], int n)
{
    int first = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] != first)
            return false;
    return true;
}
void merge(int *arr, int start, int mid, int end)
{

    int length1 = mid - start + 1;
    int length2 = end - mid;

    int *a1 = new int[length1];
    int *a2 = new int[length2];

    int i = 0;
    int j = 0;
    for (int k = start; k <= mid; k++)
    {
        a1[i] = arr[k];
        i++;
    }
    for (int k = mid + 1; k <= end; k++)
    {
        a2[j] = arr[k];
        j++;
    }

    i = 0;
    j = 0;
    int k = start;

    while (i < length1 && j < length2)
    {
        if (a1[i] < a2[j])
        {
            arr[k] = a1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
            k++;
        }
    }
    while (i < length1)
    {
        arr[k] = a1[i];
        i++;
        k++;
    }

    while (j < length2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }

    delete[] a1;
    delete[] a2;
}
void mergeSort(int *arr, int l, int r)
{

    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
int pairSum(int *arr, int n, int num)
{
    // Write your code here
    mergeSort(arr, 0, n - 1);
    int i = 0;
    int j = n - 1;
    int count = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] > num)
        {
            j--;
        }
        else if (arr[i] + arr[j] < num)
        {
            i++;
        }
        else
        {
            areSame(arr, n);
            if (areSame)
            {
                int nig = (n * (n - 1)) / 2;
                return nig;
            }

            int k = i;
            int count1 = 0;
            while (arr[k] == arr[i])
            {
                k++;
                count1++;
            }
            i = k;

            int l = j;
            int count2 = 0;
            while (arr[l] == arr[j])
            {
                l--;
                count2++;
            }
            j = l;

            count = count + (count1 * count2);
        }
    }
    return count / 2;
}