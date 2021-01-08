#include <iostream>
#include <math.h>

using namespace std;

int numPerfect(int n) {
    return floor(sqrt(n));
}

int main() {
    int n=16;
    cout << numPerfect(n) << endl;
    return 0;
}