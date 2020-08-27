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

	int row_sum[row];
	int column_sum[column];
	int s = 0;
	int k = 0;
	
	for (int i = 0; column > i; i++)
	{
		column_sum[i] = 0;
	}

	for (int i = 0; row > i; i++)
	{	
		row_sum[i] = 0;
		for (int j = 0; column > j; j++)
		{
			row_sum[i] += arr[i][j];
			column_sum[j] += arr[i][j];
		}
	}

	cout << "Row Sum" << endl;
	for (int i = 0; row > i; i++)
	{
		cout << row_sum[i] << endl;
	}

	cout << "Col Sum" << endl;
	for (int j = 0; column > j; j++)
	{
		cout << column_sum[j] << "\t";
	}
	cout << endl;

}
