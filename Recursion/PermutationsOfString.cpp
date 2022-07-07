
#include <iostream>
using namespace std;

bool ShouldSwap(string& s, int l, int currentIndex) {
    for (int i = l; i < currentIndex; i++) {
        if (s[i] == s[currentIndex])
            return 0;
    }
    return 1;
}

void Swap(string& s, int l, int r) {
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
}

void PermutationsOfString(string s, int l, int r) {
    // base case
    // if we have traversed all the elementn in the string we will return
    if (l >= r) {
        cout << s << " ";
        return;
    }

    // recursive calls
    for (int i = l; i < r; i++)
    {
      // if we need to get the uninque permutaion then only we will use the ShouldSwap function 
        if (ShouldSwap(s, l, i)) {
            Swap(s, l, i);
            PermutationsOfString(s, l + 1, r);
            // backtracking for reverting the swap and make the original string
            Swap(s, l, i);
        }
        
    }
}

int main()
{
    string input = "abc";
    PermutationsOfString(input, 0, input.length());
    // output 
    //abc acb bac bca cba cab
}
