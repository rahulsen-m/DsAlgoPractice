#include <iostream>
using namespace std;

void StockProfit(int a[], int n) {
    int maxProfit = 0, minimumSoFar = a[0];
	for (int i = 0; i < n; i++)
	{
		minimumSoFar = min(minimumSoFar, a[i]);
		maxProfit = max(a[i] - minimumSoFar, maxProfit);
	}
	cout << maxProfit;
}

int main()
{
	int a[] = { 7,1,5,3,6,4 };
	StockProfit(a, 6);
}
