#include <iostream>

// check the string is palindrom or not
bool IsPalindrome(std::string input) {
    // break condition
    if (input.length() == 0 || input.length() == 1) {
        return true;
    }

    // check both ended numbers are equal
    // if so sink the remaing input and call the functio recursively
    if (input[0] == input[input.length() - 1]) {
        return IsPalindrome(input.substr(1, input.length()-2));
    }
    return false;
}

int main()
{
    bool isPalindrome = IsPalindrome("Racecar");
    std::cout << isPalindrome;
}