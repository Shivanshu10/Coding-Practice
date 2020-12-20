#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>

using namespace std;

bool isAlNum(char ch)
{
    if (isdigit(ch) || isalpha(ch))
    {
        return true;
    }
    return false;
}

int preced(char ch)
{
    if (ch=='+' || ch == '-')
    {
        return 1;
    }
    else if (ch=='*' || ch=='/')
    {
        return 2;
    }
    else if (ch=='^')
    {
        return 3;
    }
    return 0;
}

string infixToPostfix(string exp)
{
    stack <char> s;
    s.push('#');
    string res="";
    char ch;
    for (int i=0; i<exp.length(); i++)
    {
        cout << "s: " << s.top() << endl;
        cout << "str: " << res << endl;
        ch=exp.at(i);
        if (ch=='(')
        {
            s.push('(');
        }
        else if (ch==')')
        {
            while (!(s.top() == '#') && s.top()!='(')
            {
                res=res+s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isAlNum(ch)) 
        {
            res=res+ch;
        }
        else if (!isAlNum(ch))
        {
            if ((preced(ch) > preced(s.top())))
            {
                s.push(ch);
            }
            else
            {
                while ((s.top() != '#') && preced(ch) <= preced(s.top()))
                {
                    res=res+s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
    }
    while ((s.top() != '#'))
    {
        res=res+s.top();
        s.pop();
    }
    return res;
}

int main() 
{
    //string s;
    string s="x^y/(5*z)+2";
    //getline(cin, s);
    cout << infixToPostfix(s) << endl;
    return (0);
}