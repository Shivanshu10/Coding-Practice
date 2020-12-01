#include <iostream>

using namespace std;

void disp(int *ar)
{
	// check if array created
	// if yes print one by one
	for (int i = 0; i < 7; i++)
	{
		cout << ar[i] << "  ";
	}
	cout << endl;
}

void sort(int *ar, int n)
{
	// transverse and compare
	// swap if meet condition
	int temp;
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (ar[j] > ar[j + 1])
			{
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}
	}
}

int menu(void)
{
	// Print Menu
	// Out: choice
	int choice;
	cout << "--MENU--" << endl;
	cout << "1. Display" << endl;
	cout << "2. Sort" << endl;
	cout << "3. Exit" << endl;
	cout << "YOUR CHOICE> ";
	cin >> choice;
	return choice;
}

int main()
{
	int choice;
	choice = menu(); // Print Menu
	int arr[7] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr) / sizeof(arr[0]);
	while (true)
	{
		if (choice == 1)
		{
			disp(arr);
			choice = menu();	
		}
		else if (choice == 2)
		{
			sort(arr, n);
			choice = menu();
		}
		else if (choice == 3)
		{
			exit(0);
		}
		else
		{
			cout << "Invalid choice" << endl;
			choice = menu();
		}
	}
	return 0;
}
