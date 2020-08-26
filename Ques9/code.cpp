#include <iostream>

using namespace std;

int main()
{
	int row, temp;
	cout << "Please provide the size of diagonal array in format: <n> ";
	cin >> row;
	int arr[row];
	int k = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (i != j)
			{
				cin >> temp;
			}
			else
			{
				cin >> arr[k];
				k += 1;
			}
		}
	}

	// display
	k = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (i == j)
			{
				cout << arr[k] << "\t";
				k += 1;
			}
			else
			{
				cout << "0" << "\t";
			}
		}
		cout << endl;
	}
	return 0;
}
