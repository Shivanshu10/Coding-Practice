#include <iostream>

using namespace std;

int main()
{
	int row, column;
	cout << "Please provide the size of array in format: (ROW COLUMN) ";
	cin >> row >> column;

	int arr[row][column];
	for (int i = 0; row > i; i++)
	{
		for (int j = 0; column > j; j++)
		{
			cin >> arr[i][j];
		}
	}

	int min = 0;
	int index_min = 0;
	int k;

	int points[row * column];
	for (int i = 0; row > i; i++)
	{
		for (int j = 0; column > j; j++)
		{
			if (j == 0)
			{
				min = arr[i][0];
			}
			else if (min > arr[i][j])
			{
				min = arr[i][j];
				index_min = j;
			}
		}

		for (k = 0; row > k; k++)
		{
			if (min < arr[k][index_min])
			{
				break;
			}
		}
		if (k == row)
		{
			cout << "Saddle point is: " << min << endl;
			return 0;
		}
	}
	cout << "No Saddle Point";
	cout << endl;
}
