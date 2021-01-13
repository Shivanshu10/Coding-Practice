#include <iostream>
#include <vector>

using namespace std;

class Heap {
    private:
        vector <int> *heap=NULL;
        int size=0;
        int swap(int pos1, int pos2) {
            int temp=heap->at(pos1);
            heap->at(pos1)=heap->at(pos2);
            heap->at(pos2)=temp;
            return pos1;
        }
        int mod(int n) {
            if (n>=0) {
                return n;
            }
            else {
                return 0;
            }
        }
        void reorderIns(int pos) {
            if (size<2) {
                return;
            }
            int parent=(pos/2)-1;
            while (pos>0 && heap->at(mod(parent))<heap->at(pos-1)) {
                pos=swap(mod(parent), (pos-1));
                pos++;
                parent=(pos/2)-1;
            }
        }
        void reorderDel(int pos) {
            if (size<2) {
                return;
            }
            int temp;
            bool f=true;
            while (pos<size) {
                if (pos!=0 && (2*pos-1)>=size) {
                    break;
                }
                else if (pos!=0 && (2*pos)>=size) {
                    temp=2*pos-1;
                    f=false;
                }
                if (f && pos!=0 && heap->at(2*pos-1)<heap->at(2*pos)) {
                    temp=2*pos;
                }
                else if (f && pos!=0 && heap->at(2*pos-1)>heap->at(2*pos)) {
                    temp=2*pos-1;
                }
                pos=swap(temp, pos-1);
                pos++;
                f=true;
            }
        }
    public:
        Heap() {
            heap=new vector <int>;
        }
        ~Heap() {
            delete heap;
        }
        void insert(int val) {
            heap->push_back(val);
            size++;
            reorderIns(size);
        }
        void disp() {
            for (int i=0; i<size; i++) {
                cout << heap->at(i) << " ";
            }
            cout << endl;
        }
        void del() {
            swap(0, size-1);
            heap->erase(heap->begin()+(size-1));
            heap->shrink_to_fit();
            size--;
            reorderDel(1);
        }
};

int main() {
    Heap h;
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(10);
    h.insert(1);
    h.insert(42);
    h.disp();
    h.del();
    h.del();
    h.del();
    h.disp();
    return 0;
}