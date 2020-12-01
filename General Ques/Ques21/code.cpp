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

		void reverse()
		{
			struct Node* prev;
			struct Node* curr;
			struct Node* next;

			prev = NULL;
			next = NULL;
			curr = head;
			if (head == NULL)
			{
				return;
			}
			while (curr != NULL)
			{
				next = curr -> next;
				curr -> next = prev;
				prev = curr;
				curr = next;
			}
			head = prev;
		}
};

int main() 
{
	// create a linked list object
	LinkedList ll_list;
	
	int temp, num;
	cout << "Please provide number of elemets to insert: ";
	cin >> temp;

	cout << "Please provide number of elements: ";
	for (int i = 0; i < temp; i++)
	{
		cin >> num;
		ll_list.insert_end(num);
	}

	ll_list.disp();

	ll_list.reverse();

	cout << "Reversed Linked List" << endl;
	ll_list.disp();	
	return (0);
}
