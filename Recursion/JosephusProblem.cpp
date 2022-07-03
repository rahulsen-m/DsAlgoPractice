
/// <summary>
/// Get the current gun position or the lucky position
/// </summary>
/// <param name="numberOfPeople">number of people</param>
/// <param name="rule">constaint of rotating the circle</param>
/// <returns></returns>
int JosephusProblem(int numberOfPeople, int rule) {
	// base case
	if (numberOfPeople == 1)
		return 0;

	// recursive call
	// recursively call the function with less number of people as one will be eleminated in every time. (x)
	int newAlivePersons = JosephusProblem(numberOfPeople - 1, rule);
	// after getting the position form "newAlivePersons" use the following formula to get the original position (y)
	int gunCurrentPosition = (newAlivePersons + rule) % numberOfPeople;
	/*
	*	y = (x + k) % n
	*/

	cout << "gunCurrentPosition:" << gunCurrentPosition << " newAlivePersons:" << newAlivePersons << endl;
	return gunCurrentPosition;
}


int main()
{
	int result = JosephusProblem(7, 3);

	cout << endl<< "Lucky index : " << result << endl;
}
