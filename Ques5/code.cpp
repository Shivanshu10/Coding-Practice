#include <iostream>

using namespace std;

int main()
{
	int r1, c1, temp;
	cout << "Program to Calcularte Transpose of a matrix" << endl;
	cout << "Please provide num of rows and columns for first matrix in following format: R C ";
	cin >> r1 >> c1;
	
	int arr[r1][c1];
	int transpose[r1][c1];

	cout << "Array one elements: " << endl;

	for (int i = 0; r1 > i; i++)
	{
		for (int j = 0; c1 > j; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; r1 > i; i++)
	{
		for (int j = 0; c1 > j; j++)
		{
			transpose[j][i] = arr[i][j];		
		}
	}

	cout << "OUTPUT" << endl;

	for (int i = 0; r1 > i; i++)
	{
		for (int j = 0; c1 > j; j++)
		{
			cout << transpose[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}
