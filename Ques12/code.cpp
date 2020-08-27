#include <iostream>

using namespace std;

int main()
{
	int row, column, num;
	cout << "Please provide the size of two matrix in format: (ROW COLUMN) ";
	cin >> row >> column;
	
	int r[(row * column) + 1][3];
	r[0][0] = row;
	r[0][1] = column;
	r[0][2] = 0;
	int k = 1;
	
	cout << "Please provide first matrix for addittion: " << endl;
	for (int i = 0; row > i; i++)
	{
		for (int j = 0; column > j; j++)
		{
			cin >> num;
			if (num != 0)
			{
				r[0][2] += 1;
				r[k][0] = i;
				r[k][1] = j;
				r[k][2] = num;
				k += 1;
			}
		}
	}

	int r1[(row * column) + 1][3];
	r1[0][0] = row;
	r1[0][1] = column;
	r1[0][2] = 0;
	k = 1;

	cout << "Please provide second matrix for addittion: " << endl;
	for (int i = 0; row > i; i++)
	{
		for (int j = 0; column > j; j++)
		{
			cin >> num;
			if (num != 0)
			{
				r1[0][2] += 1;
				r1[k][0] = i;
				r1[k][1] = j;
				r1[k][2] = num;
				k += 1;
			}
		}
	}

	bool find = false;
	int size;

	for (int i = 1; r[0][2] >= i; i++)
	{
		for (int j = 1; r1[0][2] >= j; j++)
		{
			if (r[i][0] == r1[j][0] && r[i][1] == r1[j][1])
			{
				r1[i][2] = r1[i][2] + r[j][2];
				find = true;
			}
		}
		if (find == false)
		{
			size = r1[0][2];
			r1[size + 1][2] = r[i][2];
			r1[size + 1][0] = r[i][0];
			r1[size + 1][1] = r[i][1];
			r1[0][2] += 1;
		}
		find = false;
	}

	cout << "Result" << endl;
	find = false;
	for (int i = 0; row > i; i++)
	{
		for (int j = 0; column > j; j++)
		{
			for (k = 1; r1[0][2] >= k; k++)
			{
				if (r1[k][0] == i && r1[k][1] == j)
				{
					cout << r1[k][2] << "\t";
					find = true;
				}
			}
			if (find == false)
			{
				cout << "0" << "\t";
			}
			find = false;
		}
		cout << endl;
	}
}
