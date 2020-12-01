#include <iostream>

using namespace std;

int* create(int& len, bool& a)
{	// get size of array
	// retrun array and set len and arr created to true
	int size;
	cout << "Size of Array: ";
	cin >> size;
	static int arr[100];
	cout << "Provide Array Data (Sorted in Ascending Order): " << endl;
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


void search(bool a, int size, int *ar, int l, int r, int x)
{
	if (a == true)
	{
		if (r >= l)
		{
			int mid = l + (r - l) / 2;
			if (ar[mid]  == x)
			{
				cout << "Element found at " << (mid + 1) << " index assuming starting as index 1" << endl;
				return;
			}
			else if (ar[mid] > x)
			{
				return search(a, size, ar, l, mid - 1, x);
			}
			return search(a, size, ar, mid + 1, r, x);
		}
		cout << "Element not found" << endl;
		return;
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
	cout << "3. Search" << endl;
	cout << "4. Exit" << endl;
	cout << "YOUR CHOICE> ";
	cin >> choice;
	return choice;
}

int main()
{
	int choice;
	choice = menu(); // Print Menu
	int *arr;
	int len;
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
			int s;
			cout << "Please provide what num to look for: ";
			cin >> s;
			search(arr_created, len, arr, 0, len - 1, s);
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
