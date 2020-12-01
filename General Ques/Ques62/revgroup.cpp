#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

class LinkedList
{
    private:
        struct Node* head=NULL;
        struct Node* tail=NULL;
        void delFirst()
        {
            if (head!=NULL)
            {
                head=head->next;
            }
        }
        void insFront(struct Node* ptr)
        {
            if (first_call)
            {
                tail=ptr;
                first_call=false;
            }
            ptr->next=head;
            head=ptr;
        }
    public:
        bool first_call=true;
        LinkedList()
        {

        }
        void insFront(int val)
        {
            struct Node* temp = new struct Node;
            temp->data=val;
            temp->next=head;
            head=temp;
            if (first_call)
            {
                tail=temp;
                first_call=false;
            }
            temp=NULL;
        }
        struct Node* getHead()
        {
            return (head);
        }
        void setHead(struct Node* ptr)
        {
            head=ptr;
        }
        struct Node* getTail()
        {
            return (tail);
        }
        void setTail(struct Node* ptr)
        {
            tail=ptr;
        }
        void copy(LinkedList* s)
        {
            if (head!=NULL)
            {
                tail->next=s->getHead();
                tail=s->getTail(); 
            }
            else
            {
                tail=s->getTail();
                head=s->getHead();
            }
        }
        LinkedList* reverseGroup(int group_size)
        {
            LinkedList *stack=new LinkedList();
            LinkedList *rev=new LinkedList();
            struct Node* itr=NULL;
            int count=group_size;
            while (head!=NULL)
            {
                while (count-- && head!=NULL)
                {
                    itr=head;
                    delFirst();
                    stack->insFront(itr);
                }
                rev->copy(stack);
                stack->first_call=true;
                stack->setHead(NULL);
                stack->setTail(NULL);
                count=group_size;
            }
            return (rev);
        }
        void disp()
        {
            struct Node* itr=head;
            while (itr!=NULL)
            {
                cout << itr->data << " ";
                itr=itr->next;
            }
            cout << endl;
        }
};

int main()
{
    LinkedList ll;
    ll.insFront(10);
    ll.insFront(9);
    ll.insFront(8);
    ll.insFront(7);
    ll.insFront(6);
    ll.insFront(5);
    ll.insFront(4);
    ll.insFront(3);
    ll.insFront(2);
    ll.insFront(1);
    ll.insFront(0);
    LinkedList* rev=ll.reverseGroup(2);
    rev->disp();
    return (0);
}