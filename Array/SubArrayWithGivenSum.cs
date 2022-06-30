public static class SubArrayWithGivenSum
    {
        public static List<int> SubArray(int[] data, int sum)
        {
            Dictionary<int, int> hash = new Dictionary<int, int>();
            int start = 0, currentSum = 0, end = -1;

            for (int i = 0; i < data.Length; i++)
            {
                currentSum = currentSum + data[i];
                // check if the given sum is found in the first index
                if (currentSum - sum == 0)
                {
                    start = 0; end = i;
                    break;
                }
                int sumToChekInTheKey = currentSum - sum;
                if (hash.ContainsKey(sumToChekInTheKey))
                {
                    start = hash[sumToChekInTheKey] + 1;
                    end = i;
                    break;
                }
                hash.Add(currentSum, i);
            }
            if(end == -1)
                return null;
            else{
                return new List<int> {start, end};
            }
        }
    }

    //main function
    var arr = new int[7] { 10, 12, 2, 4, 13, 19, 5 };
var result = SubArrayWithGivenSum.SubArray(arr, 18);
foreach (var array in result)
{
    System.Console.WriteLine(array);
}