public static int BinarySearchResult(int[] a, int left, int right, int findElement)
{
    if (right < left)
        return -1;

    var midPoint = (left + right) / 2;

    if (a[midPoint] == findElement)
    {
        return midPoint;
    }

    if (findElement < a[midPoint])
    {
        return BinarySearchResult(a, left, midPoint - 1, findElement);
    }

    return BinarySearchResult(a, midPoint + 1, right, findElement);
}

int[] a = new int[10] { 33, 99, 100, 200, 400, 600, 900, 999, 1000, 2000 };
System.Console.WriteLine(BinarySearch.BinarySearchResult(a, 0, a.Length - 1, 900));