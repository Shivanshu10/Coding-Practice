#include <iostream>

using namespace std;

int main()
{
	int r1, c1, r2, c2;
	int s = 0;
	cout << "Program to Multiply two matrices" << endl;
	cout << "Please provide num of rows and columns for first matrix in following format: R C ";
	cin >> r1 >> c1;
	cout << "Please provide num of rows and columns for second matrix in following format: R C ";
	cin >> r2 >> c2;

	if (c1 != r2)
	{
		cout << "Two matrix cannot be multipled" << endl;
		return 0;
	}
	
	int arr1[r1][c1];
	int arr2[r2][c2];
	int mul[r1][c2];

	cout << "Array one elements: " << endl;

	for (int i = 0; c1 > i; i++)
	{
		for (int j = 0; r1 > j; j++)
		{
			cin >> arr1[i][j];
		}
	}

	cout << "Array two elements: " << endl;

	for (int i = 0; c2 > i; i++)
	{
		for (int j = 0; r2 > j; j++)
		{
			cin >> arr2[i][j];
		}
	}

	for (int i = 0; r1 > i; i++)
	{
		for (int j = 0; c2 > j; j++)
		{
			for (int k = 0; r2 > k; k++)
			{
				s += arr1[i][k] * arr2[k][j];
			}
			mul[i][j] = s;
			s = 0;
		}
	}

	cout << "OUTPUT" << endl;

	for (int i = 0; r1 > i; i++)
	{
		for (int j = 0; c2 > j; j++)
		{
			cout << mul[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}
