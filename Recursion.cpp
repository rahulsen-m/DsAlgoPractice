#include <iostream>

// string reversal
std::string StringReversal(std::string input) {
    // terminating point
    if (input.length() == 0)
        return "";
    // recursive call
    std::string newInputString = input.substr(1, input.length());
    return StringReversal(newInputString) + input[0];
}

int main()
{
    std::string revesalResutl = StringReversal("Rahul");
    std::cout << revesalResutl;
}