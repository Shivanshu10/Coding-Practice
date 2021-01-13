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
    Node* ptr=n;
    Node* temp=NULL;
    Node* t=NULL;
    if (n) {
        temp=new Node(val);
        while (ptr) {
            t=ptr;
            if (ptr->data()==val) {
                return;
            }
            else if (val<ptr->data()) {
                ptr=ptr->lchild();
            }
            else {
                ptr=ptr->rchild();
            }
        }
        if (val<t->data()) {
            t->addLchild(temp);
        }
        else {
            t->addRchild(temp);
        }
    }
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