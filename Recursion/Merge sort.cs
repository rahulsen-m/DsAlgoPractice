public static class MergeSort
{
    public static void MergeSortFunc(int[] data, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            MergeSortFunc(data, start, mid);
            MergeSortFunc(data, mid + 1, end);
            Merge(data, start, mid, end);

        }
    }

    private static void Merge(int[] data, int start, int mid, int end)
    {
        // temp array to avoid the modifing of the original content
        int length = end - start + 1, i = start, j = mid + 1, k = start;
        int[] temp = new int[data.Length];

        // when both the subarrys have value then merge them in shorted order
        while (i <= mid && j <= end)
        {
            if (data[i] < data[j])
            {
                temp[k] = data[i];
                i++;
            }
            else
            {
                temp[k] = data[j];
                j++;
            }
            k++;
        }

        if (i > mid)
        {
            while (j <= end)
            {
                temp[k] = data[j];
                j++;
                k++;
            }
        }
        else
        {
            while (i <= mid)
            {
                temp[k] = data[i];
                k++;
                i++;
            }
        }
        for (int p = start; p <= end; p++)
        {
            data[p] = temp[p];
        }
    }
}

// main programme

int[] data = new int[10] { -5, 20, 103, 2, 3, 0, 8, 22, 1, 34 };
MergeSort.MergeSortFunc(data, 0, data.Length - 1);
for (int i = 0; i < data.Length; i++)
{
    System.Console.Write($"{data[i]} ");
}
// output : -5 0 1 2 3 8 20 22 34 103