#include <iostream>
#include <stack>

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

void postorderTransverse(Node* n) {
    stack <Node *> *s = new stack <Node *> ();
    Node *ptr = n;
    Node *temp=NULL;
    do {
        while (ptr!=NULL) {
            temp=ptr->rchild();
            if (temp!=NULL) {
                (*s).push(temp);
            }
            (*s).push(ptr);
            ptr=(*ptr).lchild();
        }
        ptr=(*s).top();
        (*s).pop();
        temp=ptr->rchild();
        if (temp!=NULL && (*s).top()==temp && (*s).empty()) {
            (*s).pop();
            (*s).push(ptr);
            ptr=temp;
        }
        else {
            cout << (*ptr).data() << " ";
            ptr=NULL;
        }
    }   
    while (s->empty()==false);
}

int main() {
    Node root(2);
    Node rchild(3);
    Node lchild(1);

    root.addLchild(&lchild);
    root.addRchild(&rchild);
    
    postorderTransverse(&root);
    cout << endl;
    return (0);
}