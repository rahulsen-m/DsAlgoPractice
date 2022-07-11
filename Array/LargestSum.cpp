#include <iostream>
using namespace std;

int FindLargestSum(int a[], int n) {
    int currentSum = 0, maxSum = 0;
	for (int i = 0; i < n; i++)
	{
		currentSum = currentSum + a[i];
		if (currentSum > maxSum)
			maxSum = currentSum;
		if (currentSum < 0)
			currentSum = 0;
	}
	return maxSum;
}

int main()
{
	int a[8]{ -2, -3, 4, -1, -2, 1, 5, -3 };
	cout << FindLargestSum(a, 8);
}
