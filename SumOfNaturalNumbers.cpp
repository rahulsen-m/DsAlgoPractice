int SumOfNaturalNumbers(int input)
{
    // terminating point
    if (input <= 1)
        return input;
    //recursive call
    return input + SumOfNaturalNumbers(input - 1);
}

System.Console.WriteLine(SumOfNaturalNumbers(10));