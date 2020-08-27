#include <iostream>

using namespace std;

int main()
{
	int row, temp;
	cout << "Please provide the size of array in format: <n> ";
	cin >> row;
	int k = 0;

	int arr[(row * (row + 1)) / 2];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> temp;
			if (i >= j)
			{
				arr[k] = temp;
				k += 1;
			}
		}
	}

	// display
	k = 0;
	int a = 0;
	int c = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (i >= j)
			{
				cout << arr[k] << "\t";
				k += 1;
			}
			else if (i < j)
			{
				cout << " ";
			}
		}

		cout << endl;
	}
	return 0;
}
