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

void preorderTransverse(Node* n) {
    if (n == NULL) {
        return;
    }
    cout << (*n).data() << "  ";
    preorderTransverse((*n).lchild());
    preorderTransverse((*n).rchild());
}

int main() {
    Node root(2);
    Node rchild(3);
    Node lchild(1);

    root.addLchild(&lchild);
    root.addRchild(&rchild);
    
    preorderTransverse(&root);
    cout << endl;
    return (0);
}