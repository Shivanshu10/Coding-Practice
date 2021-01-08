#include <iostream>
#include <queue>

using namespace std;

class Node
{
    private:
        Node* l_child;
        int d;
        Node* r_child;
    public:
        Node(int val) {
            l_child=NULL;
            r_child=NULL;
            d=val;
        }
        void addLchild(Node* n) {
            l_child=n;
        }
        void addRchild(Node* n) {
            r_child=n;
        }
        Node* lchild() {
            return l_child;
        }
        int data() {
            return d;
        }
        Node* rchild() {
            return r_child;
        }
};

void inorderTransverse(Node* n) {
    if (n == NULL) {
        return;
    }
    inorderTransverse((*n).lchild());
    cout << (*n).data() << "  ";
    inorderTransverse((*n).rchild());
}

int main() {
    int temp;
    queue <Node *> *q=new queue <Node *>;
    Node *root=NULL;
    Node *t=NULL;
    Node *ptr=NULL;
    cout << "Root Node Data: ";
    cin >> temp;
    root=new Node(temp);
    q->push(root);
    if (temp==-1) {
        return 0;
    }
    while (q->empty()==false) {
        ptr=q->front();
        q->pop();
        cout << "Please provide " << ptr->data() << "s left child" << endl;
        cin >> temp;
        if (temp!=-1) {
            t=new Node(temp);
            q->push(t);
            ptr->addLchild(t);
        }
        cout << "Please provide " << ptr->data() << "s right child" << endl;
        cin >> temp;
        if (temp!=-1) {
            t=new Node(temp);
            q->push(t);
            ptr->addRchild(t);
        }
    }
    inorderTransverse(root);
    cout << endl;
    return (0);
}