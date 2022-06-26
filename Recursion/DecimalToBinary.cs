string DecimalToBinary(int input, string result)
{
    // terminating point
    if (input == 0)
        return result;

    // recursive call
    result = (input % 2).ToString() + result;
    return DecimalToBinary(input / 2, result);

}


System.Console.WriteLine(DecimalToBinary(100, ""));