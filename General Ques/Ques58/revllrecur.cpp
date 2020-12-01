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
    public:
        LinkedList(int n)
        {
            insertFront(n);
        }
        void insertFront(int n)
        {
            struct Node* newnode = new struct Node;
            newnode->next=head;
            newnode->data=n;
            head=newnode;
            newnode=NULL;
        }
        struct Node* revllrecur(struct Node *node)
        {
            if (node == NULL)
            {
                return NULL;
            }
            if (node->next == NULL)
            {
                head=node;
                return node;
            }
            struct Node* node1 = revllrecur(node->next);
            node1->next=node;
            node->next=NULL;
            return node;
        }
}

int main()
{
    return (0);
}