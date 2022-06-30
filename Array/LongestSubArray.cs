public static class LongestSubArray
    {
        public static List<int> SubArryResult(int[] data, int givenSum)
        {
            int start = 0, end = -1, currentSum = 0, length = 0;
            Dictionary<int, int> hash = new Dictionary<int, int>();
            List<int> longestSubArray = new List<int>();
            for (int i = 0; i < data.Length; i++)
            {
                currentSum = currentSum + data[i];
                if (currentSum - givenSum == 0)
                {
                    start = 0;
                    end = i;
                    length = (end - start) + 1;
                }

                int numberNeedsToFindInHash = currentSum - givenSum;
                if (hash.ContainsKey(numberNeedsToFindInHash))
                {
                    start = hash[numberNeedsToFindInHash] + 1;
                    end = i;
                    length = (end - start) + 1;
                }
                // check the length and updte
                if (longestSubArray.Count < length)
                {
                    longestSubArray = new List<int>();
                    for (int e = start; e <= end; e++)
                    {
                        longestSubArray.Add(data[e]);
                    }
                }
                // add key value in hash
                if (!hash.ContainsKey(currentSum)) hash.Add(currentSum, i);
            }

            if (end == -1)
            {
                return new List<int>();
            }
            else
            {
                return longestSubArray;
            }
        }
    }


    // main function
var arr = new int[6] { -5, 8, -14, 2, 4, 12 };
var result = LongestSubArray.SubArryResult(arr, -5);
foreach (var array in result)
{
    System.Console.WriteLine(array);
}