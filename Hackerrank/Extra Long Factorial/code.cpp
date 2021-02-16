#include <bits/stdc++.h>

using namespace std;

void getDigits(short int *res, short int n) {
    for (int i=0; i<3; i++) {
        res[i]=n%10;
        n=n/10;
    }
}

void multiply(short int* n1, short int n) {
    short int mul, carry=0;
    for (int i=0; i<200; i++) {
        mul=n1[i]*n;
        mul+=carry;
        n1[i]=mul%10;
        carry=mul/10;
    }
}

void displayResult(short int* n) {
    bool prev_zero=true;
    for (int i=199; i>=0; i--) {
        if (prev_zero && n[i] != 0) {
            prev_zero=false;
        }
        if (!prev_zero) {
            cout << n[i];
        }
    }
    cout << endl;
}

void extraLongFactorials(short int n) {
    short int *n1=new short int[200];
    getDigits(n1, n);
    for (short int i=n-1; i!=0; i--) {
        multiply(n1, i);
    }
    displayResult(n1);
    delete[] n1;
}

int main()
{
    short int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
