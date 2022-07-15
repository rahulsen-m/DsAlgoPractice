#include <iostream>
#include <vector>
using namespace std;

int WaterLevel(int a[], int n) {
    vector<int> left(n); vector<int> right(n);
    int ans = 0;
    // initialize the left array
    left[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1], a[i]);
    }

    // initialize the right array
    right[n - 1] = a[n - 1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], a[i]);
    }

    // find the blocks
    for (int i = 0; i < n; i++)
    {
        ans += (min(left[i], right[i]) - a[i]);
    }

    return ans;
}

int main()
{
    int a[8] = { 3,1,2,4,0,1,3,2 };
    cout << WaterLevel(a, 8);
}
