#include <iostream>

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

Node* inPred(Node* p) {
    while (p && p->rchild()!=NULL) {
        p=p->rchild();
    }
    return p;
}

Node* inSucc(Node *p) {
     while (p && p->lchild()!=NULL) {
        p=p->lchild();
    }
    return p;
}

int main() {
    Node root(2);
    Node rchild(3);
    Node lchild(1);

    root.addLchild(&lchild);
    root.addRchild(&rchild);
    
    cout << (inSucc(&root))->data() << endl;
    return (0);
}