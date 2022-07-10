#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int> &a, int i, int j) {
    int l = i, r = j;
    while (l < r)
    {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;

        l++;
        r--;
    }
}

vector<int> CircularArrayRotation(vector<int> a, int k, vector<int> queries) {
   
    vector<int> result;
    // get the heigest number of rotation. after that the array will start repeting 
    k = k % a.size();
    if (k <= 0) {
        k += a.size();
    }
    // from start to the rotation 
    Reverse(a, 0, a.size() - k - 1);
    // from rotation count to end. -1 as index started from 0
    Reverse(a, a.size() - k, a.size() - 1);
    //Finaly reverse the whole 2 part divided array
    Reverse(a, 0, a.size() - 1);
    
    // get the elememt by the query position
    for (int i = 0; i < queries.size(); i++)
    {
        int position = queries[i];
        result.push_back(a[position]);
    }

    return result;
}

int main()
{
    vector<int> input = { 1,2,3 };
    vector<int> query = { 1,2 };
    vector<int> result = CircularArrayRotation(input, 3, query);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}
