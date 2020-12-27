#include <iostream>
#include <string>

using namespace std;

bool checkRot(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    for (int i=0; str1[i]!='\0'; i++) {
        if (str1.at(i)!=str2.at(str2.length() - i -1)) {
            return false;
        }
    }
    return true;
}

int main() {
    string str1="Gett";
    string str2="tteG";
    cout << checkRot(str1, str2) << endl;
}