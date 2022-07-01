public static class PowerSetOfGivenString
{
    public static void PowerSet(string givenString, int currentIndex, string currentString = "")
    {
        // break condition
        if (currentIndex == givenString.Length)
        {
            System.Console.Write(currentString + ", ");
            return;
        }

        PowerSet(givenString, currentIndex + 1, currentString + givenString[currentIndex]);
        PowerSet(givenString, currentIndex + 1, currentString);
    }
}

/// main program
PowerSetOfGivenString.PowerSet("abcd", 0, "");
//abcd, abc, abd, ab, acd, ac, ad, a, bcd, bc, bd, b, cd, c, d, , 