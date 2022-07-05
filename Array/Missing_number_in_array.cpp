int NaturalNumberSum(int n) {
    if (n <= 1)
        return n;
    return NaturalNumberSum(n - 1) + n;
}

int MissingNumber(vector<int>& array, int n) {
    // Your code goes here
    int result = NaturalNumberSum(n); // another process without recursion is (n * (n + 1))/2
    int sum = 0;
    for (int i = 0; i < n-1; i++)
    {
        sum += array[i];
    }
    return result - sum;
}


int main()
{
    //N = 10,  A[] = { 6,1,2,8,3,4,7,10,5}
    vector<int> vector1 = { 6,1,2,8,3,4,7,10,5 };
    int result = MissingNumber(vector1, 10);
    cout << result << endl;
    // output 9
}
