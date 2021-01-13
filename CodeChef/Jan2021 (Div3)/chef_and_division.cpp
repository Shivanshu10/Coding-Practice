#include <iostream>

using namespace std;

int main() {
    int test_cases, temp, ques_avail;
    int inp[3];
    cin >> test_cases;
    int *out=new int[test_cases];
    for (int i=0; i<test_cases; i++) {
        ques_avail=0;
        for (int j=0; j<3; j++) {
            cin >> inp[j];
        }
        for (int j=0; j<inp[0]; j++) {
            cin >> temp;
            ques_avail+=temp;
        }
        temp=ques_avail/inp[1];
        if (temp > inp[2]) {
            //cout << inp[2] << endl;
            out[i]=inp[2];
        }
        else {
            //cout << temp << endl;
            out[i]=temp;
        }
    }
    for (int i=0; i<test_cases; i++) {
        cout << out[i] << endl;
    }
    return 0;
}