#include <iostream>
using namespace std;

int PeekElement(int arr[], int n) {
    int high = n - 1, low = 0;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        // add base condition
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
            return mid;
        }
        else if (arr[mid] <= arr[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int a[9] = { 15, 3, 19, 1, 7, 11, 1, 7, 7 };
    cout << PeekElement(a, 9);
}
