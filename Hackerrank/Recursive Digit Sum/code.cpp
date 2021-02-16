#include <bits/stdc++.h>

using namespace std;

int super(long long x) {
    if (x % 9 == 0) {
        return 9;
    } 
    else {
        return x % 9;
    }
}

int main() {
    string n; int k; long long p = 0;
    cin>>n>>k;
    for(int i=0; i<n.size(); i++){
        p += n[i] - '0';
    }
    p *= k;
    cout<<super(p)<<endl;
    return 0;
}
