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

void inorderTransverse(Node* n) {
    stack <Node*> *s = new stack <Node*> ();
    Node *ptr = n;
    while (ptr!=NULL || (*s).empty()==false) {
        while (ptr!=NULL) {
            (*s).push(ptr);
            cout << (*ptr).data() << "  ";
            ptr=(*ptr).lchild();
        }
        ptr=(*s).top();
        (*s).pop();
        ptr=(*ptr).rchild();
    }
}

int main() {
    Node root(2);
    Node rchild(3);
    Node lchild(1);

    root.addLchild(&lchild);
    root.addRchild(&rchild);
    
    inorderTransverse(&root);
    cout << endl;
    return (0);
}