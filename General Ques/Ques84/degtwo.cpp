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

int countDegTwo(Node* n) {
    int x, y;
    if (n==NULL) {
        return 0;
    }
    if (n!=NULL) {
        x=countDegTwo((*n).lchild());
        y=countDegTwo((*n).rchild());
    }
    if (n->lchild() && n->rchild()) {
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
    
    cout << countDegTwo(&root) << endl;
    return (0);
}