#include <iostream>

using namespace std;

/// <summary>
/// get the lucky number 
/// </summary>
/// <param name="n">finding number</param>
/// <param name="counter">incremental rule</param>
/// <returns>is lucky or not</returns>
bool IsLucky(int n, int counter) {
    if (n < counter) {
        return true;
    }
    // using modulas to get the index of the number
    if (n % counter == 0) {
        return false;
    }
    return IsLucky(n - (n / counter), counter+1);
}

/// <summary>
/// check if the number is lucky or not
/// </summary>
/// <param name="n">finding number</param>
/// <returns>is lucky or not</returns>
bool IsLuckyWithOutRecursion(int n) {
    for (int counter = 2; counter <= n; counter++)
    {
        if (n < counter)
            return true;
        if (n % counter == 0)
            return false;
        n -= n / counter;
    }
}
int main()
{
    bool result = IsLucky(19, 2);
    cout << (result ? "Lucky" : "Unlucky") ;

    bool result2 = IsLuckyWithOutRecursion(41);
    cout << (result2 ? "Lucky" : "Unlucky");
}
