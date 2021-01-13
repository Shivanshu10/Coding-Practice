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

int height(Node* n) {
    int x, y;
    if (n==NULL) {
        return 0;
    }
    if (n!=NULL) {
        x=height((*n).lchild());
        y=height((*n).rchild());
    if (x>y) {
        return x+1;
    }
    else {
        return y+1;    
    }
}

int main() {
    Node root(2);
    Node rchild(3);
    Node lchild(1);

    root.addLchild(&lchild);
    root.addRchild(&rchild);
    
    cout << count(&root) << endl;
    return (0);
}