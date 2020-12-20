#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>

using namespace std;

bool isNum(char c) {
    if (isdigit(c))
    {
        return true;
    }
    return false;
}

int calc(int op1, char ch, int op2) {
    if (ch == '+') {
        return (op1 + op2);
    }
    else if (ch == '-') {
        return (op1 - op2);
    }
    else if (ch == '*') {
        return (op1 * op2);
    }
    else if (ch == '/') {
        return (op1 / op2);
    }
    else if (ch == '^') {
        return (op1 ^ op2);
    }
}

int evalPost(string expr) {
    stack <int> s;
    char ch;
    int op1, op2, res;
    for (int i=0; i<expr.length(); i++) {
        ch=expr.at(i);
        if (!(isNum(ch))) {
            op1=s.top();
            s.pop();
            op2=s.top();
            s.pop();
            res=calc(op2, ch, op1);
            s.push(res);
        }
        else {
            res=ch-'0';
            s.push(res);
        }
    }
    return s.top();
}

int main() {
    string s="231*+9-";
    cout << evalPost(s) << endl;
    return (0);
}