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

int countLeaf(Node* n) {
    int x, y;
    if (n==NULL) {
        return 0;
    }
    if (n!=NULL) {
        x=countLeaf((*n).lchild());
        y=countLeaf((*n).rchild());
    }
    if (n->lchild()==NULL && n->rchild()==NULL) {
        return x+y+1;
    }
    else {
        return x+y;
    }
}

int main() {
    Node root(2);
    Node rchild(3);
    Node lchild(1);

    root.addLchild(&lchild);
    root.addRchild(&rchild);
    
    cout << countLeaf(&root) << endl;
    return (0);
}