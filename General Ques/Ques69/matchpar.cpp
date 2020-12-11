#include<iostream>
#include<string>
#include<stack>

using namespace std;

char getOpp(char c)
{
    if (c == ')')
    {
        return '(';
    }
    else if (c == ']')
    {
        return '[';
    }
    else
    {
        return '{';
    }
}

bool matchPar(string str)
{
    char round_opp=')';
    char square_opp=']';
    char curly_opp='}';    
    stack <char> *s=new stack <char>();
    char c, t;
    for (int i=0; i<str.length(); i++)
    {
        c=str.at(i);
        if (c=='(' || c=='[' || c=='{')
        {
            (*s).push(c);
        }
        else if (c==')' || c==']' || c=='}')
        {
            if ((*s).empty())
            {
                return false;
            }
            if ((*s).top()==getOpp(c))
            {
                (*s).pop();
            }
        }
    }
    if (!(*s).empty())
    {
        return false;
    }
    return true;
}

int main()
{
    string str="({}())";
    //getline(cin, str);
    cout << matchPar(str) << endl;
    return(0);
}