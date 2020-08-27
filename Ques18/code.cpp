#include <iostream>

using namespace std;

void fillSpiralOrder(int n)
{
	int arr[n][n];
	int dir = 0;

}

int main()
{
	int num;
	cout << "Please provide number whose square to be filled in spiral order: ";
	cin >> num;

	int arr[num][num];

	int dir = 0;
	int top = 0;
	int left = 0;
	int right = num - 1;
	int bottom = num - 1;
	int a = 1;
	while (top <= bottom && left <= right)
	{
		if (dir == 0)
		{
			for (int i = left; i <= right; i++)
			{
				arr[top][i] = a;
				a += 1;
			}
			top += 1;
			dir = 1;
		}
		else if (dir == 1)
		{
			for (int i = top; i <= bottom; i++)
			{
				arr[i][right] = a;
				a += 1;
			}
			right -= 1;
			dir = 2;
		}
		else if (dir == 2)
		{
			for (int i = right; i >= left; i--)
			{
				arr[bottom][i] = a;
				a += 1;
			}
			bottom -= 1;
			dir = 3;
		}
		else if (dir == 3)
		{
			for (int i = bottom; i >= top; i--)
			{
				arr[i][left] = a;
				a += 1;
			}
			left += 1;
			dir = 0;
		}
	}
	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
