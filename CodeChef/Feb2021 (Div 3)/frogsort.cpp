#include<bits/stdc++.h>

using namespace std;

int checkWeightSorted(pair<int, int>* arr, int size) {
    for (int i=0; i<size; i++) {
        if (i!=size-1 && (arr[i].first > arr[i+1].first)) {
            return i;
        }
        if (i!=size-1 && (arr[i].second==arr[i+1].second)) {
            return i+1;
        }
    }
    return -1;
}

void swap(pair<int, int>* arr, int i, int j, int* l) {
    int temp1, temp2, temp3, temp4, temp5;
    temp1=arr[i].first;
    temp2=arr[j].first;
    temp3=arr[i].second;
    temp4=arr[j].second;

    temp5=l[i];
    l[i]=l[j];
    l[j]=temp5;

    arr[i].first=temp2;
    arr[j].first=temp1;

    arr[i].second=temp4;
    arr[j].second=temp3;
}

void bubbleSortSecond(pair<int, int>* arr, int s, int* l) {
    bool sorted;
    for (int i=0; i<s; i++) {
        sorted=false;
        for (int j=0; j<s-i-1; j++) {
            if (arr[j].second > arr[j+1].second) {
                swap(arr, j, j+1, l);
                sorted=true;
            }
        }
        if (sorted==false) {
            return;
        }
    }
}

int numHit(pair<int, int>* arr1, int size, int* l) {
    int pos, jumps=0;
    pos=checkWeightSorted(arr1, size);
    while (pos!=-1) {
        if (1) {
            arr1[pos].second+=l[pos];
            /* cout << endl;
            cout << "ARR FIRST" << endl;
            for (int i=0; i<size; i++) {
                cout << arr1[i].first << " ";
            }
            cout << endl;
            cout << "ARR SECOND" << endl;
            for (int i=0; i<size; i++) {
                cout << arr1[i].second << " ";
            }
            cout << endl;
            cout << "Length" << endl;
            for (int i=0; i<size; i++) {
                cout << l[i] << " ";
            } */
            bubbleSortSecond(arr1, size, l);
            /* cout << endl;
            cout << "ARR FIRST AFTER SORT" << endl;
            for (int i=0; i<size; i++) {
                cout << arr1[i].first << " ";
            }
            cout << endl;
            cout << "ARR SECOND AFTER SORT" << endl;
            for (int i=0; i<size; i++) {
                cout << arr1[i].second << " ";
            }
            cout << endl;
            cout << "LENGTH AFTER SORT" << endl;
            for (int i=0; i<size; i++) {
                cout << l[i] << " ";
            }
            cout << endl; */
            jumps++;
            pos=checkWeightSorted(arr1, size);
            }
    }
    return jumps;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    long test_cases;
    int n;
    cin >> test_cases;
    int *out=new int[test_cases];
    for (int i=0; i<test_cases; i++) {
        cin >> n;
        pair <int, int> *w=new pair <int, int>[n];
        int *l=new int[n];
        for (int j=0; j<n; j++) {
            cin >> w[j].first;
            w[j].second=j;
        }
        for (int k=0; k<n; k++) {
            cin >> l[k];
        }
        out[i]=numHit(w, n, l);
        delete[] w;
        delete[] l;
    }
    for (int i=0; i<test_cases; i++) {
        cout << out[i] << endl;
    }
    return 0;
}