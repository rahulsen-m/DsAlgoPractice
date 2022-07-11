#include <iostream>
using namespace std;
int MajorityElement(int a[], int n) {
    int count = 1, result = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[result])
			count++;
		else count--;

		if (count == 0) {
			count = 1;
			result = i;
		}
	}
	return a[result];
}

int main()
{
	int a[9] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 };
	int result = MajorityElement(a, 9);
	cout << result;
}
