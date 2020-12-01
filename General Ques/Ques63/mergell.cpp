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
    struct Node *head = NULL;

public:
    void insFront(int val)
    {
        struct Node *temp = new struct Node;
        temp->data = val;
        temp->next = head;
        head = temp;
        temp = NULL;
    }
    void disp()
    {
        struct Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    friend LinkedList *merge(LinkedList first, LinkedList second);
};

LinkedList *merge(LinkedList first_ll, LinkedList second_ll)
{
    LinkedList *merge = new LinkedList();
    struct Node *first = first_ll.head;
    struct Node *second = second_ll.head;
    struct Node *temp = NULL;
    struct Node *last = NULL;
    while (first != NULL)
    {
        if (second != NULL)
        {
            if ((first->data) < (second->data))
            {
                temp = first->next;
                if (merge->head == NULL)
                {
                    merge->head = first;
                    first->next = NULL;
                    last = first;
                }
                else
                {
                    last->next = first;
                    first->next = NULL;
					last = last->next;
                }
                first = temp;
            }
            else if ((first->data) > (second->data))
            {
                temp = second->next;
                if (merge->head == NULL)
                {
                    merge->head = second;
                    second->next = NULL;
                    last = second;
                }
                else
                {
                    last->next = second;
                    second->next = NULL;
					last=last->next;
                }
                second = temp;
            }
            else if ((first->data) == (second->data))
            {
                temp = first->next;
                if (merge->head == NULL)
                {
                    merge->head = first;
                    first->next = NULL;
                    last = first;
                }
                else
                {
                    last->next = first;
                    first->next = NULL;
					last=last->next;
                }
                first = temp;
                second = second->next;
            }
        }
		else
		{
			temp = first->next;
            if (merge->head == NULL)
            {
                merge->head = first;
                first->next = NULL;
                last = first;
            }
            else
            {
                last->next = first;
                first->next = NULL;
				last=last->next;
            }
            first = temp;
		}
    }
    while (second != NULL)
    {
        temp = second->next;
        if (merge->head == NULL)
        {
            merge->head = second;
            second->next = NULL;
            last = second;
        }
        else
        {
            last->next = second;
            second->next = NULL;
			last=last->next;
        }
        second = temp;
    }
    return (merge);
}

int main()
{
    LinkedList first;
    LinkedList second;
    first.insFront(6);
    first.insFront(5);
    first.insFront(4);
    first.insFront(3);
    first.insFront(2);
    first.insFront(1);
    second.insFront(12);
    second.insFront(11);
    second.insFront(11);
    second.insFront(9);
    second.insFront(6);
    second.insFront(5);
	LinkedList* merged=merge(first, second);
	merged->disp();
    return (0);
}