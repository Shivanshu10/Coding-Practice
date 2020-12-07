#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

class LinkedList
{
    private:
        struct Node* head;
    public:
        LinkedList()
        {
            head=NULL;
        }
        void insFront(int val)
        {
            struct Node* ptr=new struct Node;
            ptr->data=val;
            ptr->next=head;
            head=ptr;
            ptr=NULL;
        }
        friend struct Node* checkIntersect(LinkedList& ll1, LinkedList& ll2);
        friend void makeIntersect(LinkedList& ll1, LinkedList& ll2, int point);
};

struct Node* checkIntersect(LinkedList& ll1, LinkedList& ll2)
{
    struct Node* ptr1=ll1.head;
    struct Node* ptr2=ll2.head;

    if (ptr1 == NULL || ptr2 == NULL)
    {
        return NULL;
    }
    //int count=0;
    //while (ptr1 != ptr2 && count<2)
    while (ptr1!=ptr2)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;

        if (ptr1==ptr2)
        {
            return (ptr1);
        }

        if (ptr1==NULL)
        {
            ptr1=ll2.head;
            //count++;
        }

        if (ptr2==NULL)
        {
            ptr2=ll1.head;
            //count++;
        }
    }
    return (ptr1);
}

void makeIntersect(LinkedList& ll1, LinkedList& ll2, int point)
{
    struct Node* ptr=ll1.head;
    if (ptr==NULL)
    {
        return;
    }
    while ((ptr->next)!=NULL)
    {
        ptr=ptr->next;
    }
    int count=0;
    struct Node* temp=ptr;
    ptr=ll2.head;
    if (ptr==NULL)
    {
        return;
    }
    while (count != point && (ptr->next)!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    temp->next=ptr;
}

int main()
{
    LinkedList l1, l2;
    l1.insFront(4);
    l1.insFront(3);
    l1.insFront(2);
    l1.insFront(1);
    l2.insFront(10);
    l2.insFront(9);
    l2.insFront(8);
    l2.insFront(7);
    l2.insFront(6);
    l2.insFront(5);
    //makeIntersect(l1, l2, 2);
    struct Node* out=checkIntersect(l1, l2);
    if (out!=NULL)
    {
        cout << out->data << endl;
    }   
    return (0);
}