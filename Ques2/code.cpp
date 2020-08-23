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

void dup_del(bool a, int& size, int *ar)
{
	// check if array was created
	// linear search to find dup and shift to overwrite hence delete
	if (a == true)
	{
		for (int i = 0; size > i; i++)
		{
			for (int j = i + 1; size > j; j++)
			{
				if (ar[i] == ar[j])
				{
					for (int k = j + 1; size > k; k++)
					{
						ar[k - 1] = ar[k];
					}
					size -= 1;
					i = 0;
					j = 0;
				}
			}
		}
	}
	else
	{
		cout << "Please create an array first" << endl;
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
	cout << "3. Unique Only (Remove Duplicate)" << endl;
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
			dup_del(arr_created, len, arr);
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
