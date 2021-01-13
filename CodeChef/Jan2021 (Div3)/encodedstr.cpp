#include <iostream>
#include <string>

using namespace std;

int power(int x, unsigned int y) 
{ 
    int res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}

int main() {
    int test_cases, str_size, index;
    char temp;
    cin >> test_cases;
    string *out=new string[test_cases];
    // vector <bool> *encoded_str=new vector <bool> encoded_str;
    for (int i=0; i<test_cases; i++) {
        out[i]="";
        cin >> str_size;
        str_size=str_size/4;
        // encoded_str=new bool[str_size];
        for (int j=0; j<str_size; j++) {
            index=0;
            for (int k=3; k>=0; k--) {
                temp=getchar();
                if (temp=='1') {
                    index+=power(2, k);
                }
                else if (temp=='\n') {
                    k++;
                }
            }
            out[i].push_back((char) (97+index));
        }
    }
    for (int i=0; i<test_cases; i++) {
        cout << out[i] << endl;
    }
    return 0;
}