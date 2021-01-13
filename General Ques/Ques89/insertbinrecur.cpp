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

void inorderTransverse(Node* n) {
    if (n == NULL) {
        return;
    }
    inorderTransverse((*n).lchild());
    cout << (*n).data() << "  ";
    inorderTransverse((*n).rchild());
}

void insert(Node* n, int val) {
    static Node* prev=NULL;
    if (n==NULL) {
        if (prev->data()>val) {
            Node* temp=new Node(val);
            prev->addLchild(temp);
            return;
        }
        else {
            Node* temp=new Node(val);
            prev->addRchild(temp);
            return;
        }
    }
    if (val==n->data()) {
        return;
    }
    else if (val<n->data()) {
        prev=n;
        return insert(n->lchild(), val);
    }
    prev=n;
    return insert(n->rchild(), val);
}

int main() {
    int temp, num;
    Node *root=NULL;
    cout << "Please provide root data: ";
    cin >> temp;
    if (temp!=-1) {
        root=new Node(temp);
    }
    cout << "Please provide number of keys to be inserted: ";
    cin >> num;
    for (int i=0; i<num; i++) {
        cout << "Please provide key: ";
        cin >> temp;
        insert(root, temp);
    }
    inorderTransverse(root);
    cout << endl;
}