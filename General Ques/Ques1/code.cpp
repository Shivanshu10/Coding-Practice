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

void search(bool a, int size, int *ar)
{
	// Check if array was created or not
	// Linear Search
	// iterate over and compare
	int look;
	if (a == true)
	{
		bool found = false;
		cout << "What to Search for: ";
		cin >> look;
		for (int i = 0; i < size; i++)
		{
			if (ar[i] == look)
			{
				cout << "Found at Index: " << (i + 1) << "Counting begining as index 1" << endl;
				found = true;
			}
		}
		if (found != true)
		{
			cout << "Not Found!!!" << endl;
		}
	}

	else
	{
		cout << "Array not recide in the memory!! Please create one." << endl;
	}
}

void insert(bool a, int& size, int *ar)
{
	// check if array created
	// get insert pos and num
	// check if array has space to shift
	// shift
	// increment array size by 1
	if (a == true)
	{
		int index, num, i;
		cout << "Please provide where to insert (Assume Begnning has index 1): ";
		cin >> index;
		if (index > size + 1)
		{
			cout << "Index Should be smaller than or equal to array size of " << size << endl; 
			return;
		}
		cout << "Please provide number to insert: ";
		cin >> num;
		int num_of_shifts;
		num_of_shifts = size - index + 1;
		if (size + num_of_shifts <= 100)
		{
			for (i = size - 1; i != (index - 2); i--)
			{
				ar[i + 1] = ar[i];
			}
			ar[i + 1] = num;
			size += 1;
		}
		else
		{
			cout << "Array excluding the limiting size of 100" << endl;
		}
	}
	else
	{
		cout << "Array not created" << endl;
	}	
}

void del(bool a, int& size, int *ar)
{
	// check if array was created
	// can we delete that index
	// shift to ocverwrite that index
	if (a == true)
	{
		int index;
		cout << "Please provide index to delete: ";
		cin >> index;
		if (index > size)
		{
			cout << "Cannot delete index bigger than array size" << endl;
			return;
		}
		for (int i = index; i < size; i++)
		{
			ar[i-1] = ar[i];
		}
		size -= 1;
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
	cout << "3. Insert" << endl;
	cout << "4. Delete" << endl;
	cout << "5. Search" << endl;
	cout << "6. Exit" << endl;
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
			insert(arr_created, len, arr);
			choice = menu();
		}
		else if (choice == 4)
		{
			del(arr_created, len, arr);
			choice = menu();
		}
		else if (choice == 5)
		{
			search(arr_created, len, arr);
			choice = menu();
		}
		else if (choice == 6)
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
