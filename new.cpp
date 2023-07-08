#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    int start, count, x, maxcount = -1, index1, index2;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        start = arr[i];
        int x = arr[i];
        while (m.count(x + 1) > 0)
        {
            count++;
            x++;
        }
        while (m.count(start - 1) > 0)
        {
            count++;
            start--;
        }
        if (count == 0)
            v[0] = arr[0];
        else if (count > maxcount)
        {
            v[0] = start;
            v[1] = start + count;
            maxcount = count;
        }
        else if (count == maxcount)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == v[0])
                    index1 = i;
                if (arr[i] == start)
                    index2 = i;
            }
            if (index2 < index1)
            {
                v[0] = start;
                v[1] = start + count;
            }
        }
    }
    return v;
}