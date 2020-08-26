#include <iostream>

using namespace std;

int main()
{
	int row, temp;
	cout << "Please provide the size of sqaure matrix: n ";
	cin >> row;
	
	int arr[3 * row - 2];
	int k = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> temp;
			if ((i == j) || (i == j + 1) || (i == j - 1))
			{
				arr[k] = temp;
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
			if ((i == j) || (i == j + 1) || (i == j - 1))
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
