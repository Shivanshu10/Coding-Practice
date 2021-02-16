#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases;
    long n, x, y, z, temp;
    long *out = new long[test_cases];
    long *arr=NULL;
    cin >> test_cases;
    for (int i=0; i<test_cases; i++) {
        cin >> n;
        arr=new long[n];
        for (int j=0; j<n; j++) {
            cin >> temp;
            arr[j]=temp;
        }
        sort(arr, arr+n);
        x=arr[0];
        z=arr[n-1];
        y=arr[n/2];
        delete[] arr;
        arr=NULL;
        out[i]=abs(z-x) + abs(y-z) + abs(x-y);
    }
    for (int i=0; i<test_cases; i++) {
        cout << out[i] << endl;
    }
    return 0;
}