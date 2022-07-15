#include <iostream>
using namespace std;

int MaxProfit(int a[], int n) {
    int profit = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1]) {
			profit += (a[i] - a[i - 1]);
		}
	}
	return profit;
}

int main()
{
	int a[8] = { 5,2,6,1,4,7,3,6 };
	cout << MaxProfit(a, 8);
}
