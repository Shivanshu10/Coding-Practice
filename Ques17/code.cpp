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

	int dir = 0;
	int top = 0;
	int bottom = row - 1;
	int left = 0;
	int right = column - 1;

	while (top <= bottom && left <= right)
	{
		if (dir == 0)
		{
			for (int i = left; i <= right; i++)
			{
				cout << arr[top][i] << "\t";
			}
			top += 1;
			dir = 1;
		}
		else if (dir == 1)
		{
			for (int i = top; i <= bottom; i++)
			{
				cout << arr[i][right] << "\t";
			}
			right -= 1;
			dir = 2;
		}
		else if (dir == 2)
		{
			for (int i = right; i >= left; i--)
			{
				cout << arr[bottom][i] << "\t";
			}
			bottom -= 1;
			dir = 3;
		}
		else if (dir == 3)
		{
			for (int i = bottom; i >= top; i--)
			{
				cout << arr[i][left] << "\t";
			}
			left += 1;
			dir = 0;
		}
	}
	cout << endl;
}
