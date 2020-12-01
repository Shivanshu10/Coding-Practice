#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

class LinkedList
{
	private:
		struct Node* head;
	
	public:
		LinkedList()
		{
			head = NULL;
		}

		void insert_begin(int val)
		{
			// create a node
			struct Node* n = new struct Node;
			n -> data = val;
			n -> next = head;

			// point head to it
			head = n;
			n = NULL;
		}

		void insert_int(int key, int val, bool dir)
		{
			// create a node
			struct Node* n = new struct Node;
			n -> data = val;
			n -> next = NULL;

			// search val
			struct Node* ptr;
			ptr = head;
			if (head == NULL)
			{
				return;
			}
			if (dir == true)
			{
				while ((ptr -> data) != key)
				{
					ptr = ptr -> next;

					if (ptr == NULL)
					{
						return;
					}
				}
				n -> next = ptr -> next;
				ptr -> next = n;
				n = NULL;
				ptr = NULL;
			}
			else if (dir == false)
			{
				if (ptr -> next == NULL)
				{
					if (ptr -> data == key)
					{
						n -> next = head;
						head = n;
						ptr = NULL;
						n = NULL;
						return;
					}
				}
				while (((ptr -> next) -> data) != key)
				{
					ptr = ptr -> next;

					if ((ptr -> next) == NULL)
					{
						return;
					}
				}
				n -> next = ptr -> next;
				ptr -> next = n;
				ptr = NULL;
				n = NULL;
			}
		}

		void insert_end(int val)
		{
			// create a node
			struct  Node* n = new struct Node;
			n -> data = val;
			n -> next = NULL;


			// insert to end
			struct Node* ptr;
			ptr = head;

			if (head == NULL)
			{
				head = n;
				n = NULL;
				return;
			}

			while ((ptr -> next) != NULL)
			{
				ptr = ptr -> next;
			}
			ptr -> next = n;
			n = NULL;
		}

		void delete_begin()
		{
			struct Node* ptr;
			ptr = head;
			if (head == NULL)
			{
				return;
			}
			head = head -> next;
			ptr -> next = NULL;
			delete(ptr);
			ptr = NULL;
		}

		void delete_int_val(int val)
		{
			struct Node* ptr;
			ptr = head;

			if (head == NULL)
			{
				return;
			}
			while (ptr != NULL)
			{
				if ((ptr -> next) == NULL)
				{
					if (ptr -> data == val)
					{
						delete (ptr);
						head = NULL;
					}
				}
				else if (((ptr -> next) -> data) == val)
				{
					struct Node* temp;
					temp = ptr -> next;
					ptr -> next = temp -> next;
					temp -> next = NULL;
					delete(temp);
					temp = NULL;
					ptr = NULL;
				}
				ptr = ptr -> next;
			}
		}

		void delete_end()
		{
			struct Node* ptr;
			ptr = head;
			if (head == NULL)
			{
				return;
			}
			else if ((ptr -> next) == NULL)
			{
				return;
			}
			while ((ptr -> next) -> next != NULL)
			{
				ptr = ptr -> next;
			}
			delete((ptr -> next));
			ptr -> next = NULL;
			ptr = NULL;
		}

		void search(int num)
		{
			int count = 0;
			struct Node* ptr;
			ptr = head;
			while (ptr != NULL)
			{
				if ((ptr -> data) == num)
				{
					cout << "Found at index " << count << endl;
				}
				count++;
				ptr = ptr -> next;
			}
		}

		void disp()
		{
			// transverse and display
			int num;
			struct Node* ptr;
			ptr = head;

			cout << "Data in linked list are: ";
			while (ptr != NULL)
			{
				num = ptr -> data;
				cout << num << "   ";
				
				ptr = ptr -> next;
			}
			cout << endl;
		}

		void count_key(int k)
		{
			int count = 0;
			struct Node* ptr;
			ptr = head;

			while (ptr != NULL)
			{
				if ((ptr -> data) == k)
				{
					count++;
				}
				ptr = ptr -> next;
			}
			cout << "Number of Times key has occured: " << count << endl;
		}
};

int menu()
{
	int choice;
	cout << "--MENU--" << endl;
	cout << "1. Insert at begin" << endl;
	cout << "2. Insert at end" << endl;
	cout << "3. Insert in between" << endl;
	cout << "4. Delete from begin" << endl;
	cout << "5. Delete from end" << endl;
	cout << "6. Delete specific node with some val" << endl;
	cout << "7. Display node position after seraching" << endl;
	cout << "8. Dispaly all nodes values" << endl;
	cout << "9. Exit" << endl;

	cout << "Your Choice> ";
	cin >> choice;
	return (choice);
}

int main() 
{
	// create a linked list object
	LinkedList ll_list;
	int choice, temp, key, val;
	while (true)
	{
		choice = menu();

		if (choice == 1)
		{
			cout << "Please provide value to insert: ";
			cin >> temp;

			ll_list.insert_begin(temp);
		}

		else if (choice == 2)
		{
			cout << "Please provide value to insert: ";
			cin >> temp;

			ll_list.insert_end(temp);
		}

		else if (choice == 3)
		{
			cout << "Please provide key where to insert: ";
			cin >> key;

			cout << "Please provide to insert after or before the key" << endl;
			cout << "Choose 1 for after key and 0 for before the key: " << endl;
			cin >> temp;

			cout << "Please provide value to insert: ";
			cin >> val;

			ll_list.insert_int(key, val, temp);
		}

		else if (choice == 4)
		{
			ll_list.delete_begin();
		}

		else if (choice == 5)
		{
			ll_list.delete_end();
		}

		else if (choice == 6)
		{
			cout << "Please provide value to delete: ";
			cin >> val;

			ll_list.delete_int_val(val);
		}

		else if (choice == 7)
		{
			cout << "Please provide val to search in linked list: ";
			cin >> val;

			ll_list.search(val);
		}

		else if (choice == 8)
		{
			ll_list.disp();
		}

		else if (choice == 9)
		{
			return (0);
		}

		else
		{
			cout << "Invalid choice" << endl;
		}
	}
	return (0);
}
