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
    bool isLoop()
    {
        struct Node* slow=head;
        struct Node* fast=head;
        bool loop=true;
        do 
        {
            if (fast==NULL)
            {
                loop=false;
                break;
            }
            slow=slow->next;
            fast=(fast->next)->next;
        }
        while (fast != slow);
        return (loop);
    }
    void makeLoop()
    {
        struct Node* ptr=head;
        while ((ptr->next) != NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=head;
    }
};

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
    first.makeLoop();
    cout << first.isLoop() << endl;
    return (0);
}