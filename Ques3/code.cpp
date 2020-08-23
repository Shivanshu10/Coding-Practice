#include <iostream>

using namespace std;

int* create(int& len, bool& a)
{	// get size of array
	// retrun array and set len and arr created to true
	int size;
	cout << "Size of Array: ";
	cin >> size;
	static int arr[100];
	cout << "Provide Array Data: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	a = true;
	len = size;
	return arr;
}

void disp(bool a, int size, int *ar)
{
	// check if array created
	// if yes print one by one
	if (a == true)
	{
		for (int i = 0; i < size; i++)
		{
			cout << ar[i] << "  ";
		}
		cout << endl;
	}
	else
	{
		cout << "Array not recide in the memory!! Please create one." << endl;
	}
}

void rev_arr(bool a, int size, int *ar)
{
	if (a == true)
	{
		// transverse and swap index
		int temp;
		for (int i = 0; (size / 2) > i; i++)
		{
			temp = ar[i];
			ar[i] = ar[size - i - 1];
			ar[size - i - 1] = temp;
		}
	}
	else
	{
		cout << "Please create an array first." << endl;
	}
}

int menu(void)
{
	// Print Menu
	// Out: choice
	int choice;
	cout << "--MENU--" << endl;
	cout << "1. Create" << endl;
	cout << "2. Display" << endl;
	cout << "3. Reverse Array" << endl;
	cout << "4. Exit" << endl;
	cout << "YOUR CHOICE> ";
	cin >> choice;
	return choice;
}

int main()
{
	int choice;
	choice = menu(); // Print Menu
	int* arr; // array
	int len; // len of array
	bool arr_created = false;
	while (true)
	{
		if (choice == 1)
		{
			arr = create(len, arr_created);
			choice = menu();
		}
		else if (choice == 2)
		{
			disp(arr_created, len, arr);
			choice = menu();	
		}
		else if (choice == 3)
		{
			rev_arr(arr_created, len, arr);
			choice = menu();
		}
		else if (choice == 4)
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
