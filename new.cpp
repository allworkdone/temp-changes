int tripletSum(int *input, int n, int num)
{
    int count = 0;
    sort(input, input + n);

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = input[i] + input[j] + input[k];

            if (sum == num)
            {
                int left = j, right = k;
                int val1 = input[j], val2 = input[k];
                if (val1 == val2)
                {
                    int freq = right - left + 1;
                    count += (freq * (freq - 1)) / 2;
                    break;
                }
                int count1 = 0, count2 = 0;
                while (j < k && input[j] == val1)
                {
                    j++;
                    count1++;
                }
                while (k >= j && input[k] == val2)
                {
                    k--;
                    count2++;
                }
                count += count1 * count2;
            }
            else if (sum < num)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    return count;
}