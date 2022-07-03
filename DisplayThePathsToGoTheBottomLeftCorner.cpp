#include <iostream>
#include "DsAndAlgo.h"
using namespace std;

/// <summary>
/// Get the number paths to get into the left bottom corner
/// </summary>
/// <param name="rows">rows</param>
/// <param name="columns">columns</param>
/// <returns>total count</returns>
int NumberOfPathstoGetInTheLeftBottomCorner(int rows, int columns) {
	if (rows == 1 || columns == 1)
		return 1;

	int smallMatrix1 = NumberOfPathstoGetInTheLeftBottomCorner(rows-1, columns);
	int smallMatrix2 = NumberOfPathstoGetInTheLeftBottomCorner(rows, columns - 1);
	return smallMatrix1 + smallMatrix2;
}

/// <summary>
/// Get the paths
/// </summary>
/// <param name="rows">rows</param>
/// <param name="columns">columns</param>
/// <param name="pathArray">result Array</param>
/// <returns>path array</returns>
int DisplayThePathsToGoTheBottomLeftCorner(int rows, int columns, string pathArray[]) {
	string temp[1000];
	int c = 0;
	// break condition

	// if row is 1 then we reached the last row 
	if (rows == 1)
	{
		pathArray[0] = "";
		// As we are in the last row , we only move horizentaly
		/* As the last column is the destination column(right buttom corner), 
		* so we removed the last column and add 'H' for remaing boxes in the matrix*/
		for (int i = 0; i < columns -1 ; i++)
		{
			pathArray[0] += 'H';
		}
		return 1;
	}

	// if the column is 1 then we reached at the last column 
	if (columns == 1) {
		pathArray[0] = "";
		// As we are in the last column , we only move vertically
		/* As the last row is the destination column(right buttom corner),
		* so we removed the last row and add 'V' for remaing boxes in the matrix*/
		for (int i = 0; i < rows -1; i++)
		{
			pathArray[0] += 'V';
		}
		return 1;
	}

	// recursive call
	int smallMatirxCount1 = DisplayThePathsToGoTheBottomLeftCorner(rows-1, columns, pathArray);
	// reducing row, we need to go Vertically
	for (int i = 0; i < smallMatirxCount1; i++)
	{
		temp[c] = pathArray[i] + 'V';
		c++;
	}

	int smallMatrixCount2 = DisplayThePathsToGoTheBottomLeftCorner(rows, columns - 1, pathArray);
	// reducing column, we need to go Horizentaly
	for (int i = 0; i < smallMatrixCount2; i++)
	{
		temp[c] = pathArray[i] + 'H';
		c++;
	}


	// copy the temp array to the resultArray
	for (int i = 0; i < smallMatirxCount1 + smallMatrixCount2; i++)
	{
		pathArray[i] = temp[i];
	}
	return smallMatirxCount1 + smallMatrixCount2;
}

int main()
{
	string output[1000];
	int outputPathsSize = DisplayThePathsToGoTheBottomLeftCorner(2, 3, output);

	int numberOfPaths = NumberOfPathstoGetInTheLeftBottomCorner(2, 3);
	cout <<"number of paths : " <<  numberOfPaths << endl;
	cout << "Paths" << endl;
	for (int i = 0; i < outputPathsSize; i++)
	{
		cout << output[i] << endl;
	}
}
