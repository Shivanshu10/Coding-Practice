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

void del(Node* n, int val) {
    static Node* prev=NULL;
    if (n==NULL) {
        return;
    }
    if (val==n->data()) {
        if (val<prev->data()) {
            delete n;
            prev->addLchild(NULL);
        }
        else {
            delete n;
            prev->addRchild(NULL);
        }
        return;
    }
    else if (val<n->data()) {
        prev=n;
        return del(n->lchild(), val);
    }
    prev=n;
    return del(n->rchild(), val);
}

void inorderTransverse(Node* n) {
    if (n == NULL) {
        return;
    }
    inorderTransverse((*n).lchild());
    cout << (*n).data() << "  ";
    inorderTransverse((*n).rchild());
}


int main() {
    Node* root=new Node(2);
    Node* rchild=new Node(3);
    Node* lchild=new Node(1);

    root->addLchild(lchild);
    root->addRchild(rchild);
    
    inorderTransverse(root);
    cout << endl;
    del(root, 1);
    inorderTransverse(root);
    cout << endl;
    return (0);
}