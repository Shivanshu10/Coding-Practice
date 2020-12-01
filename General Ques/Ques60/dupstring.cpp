#include <iostream>

using namespace std;

bool dupString(char str[])
{
    long int hash=0, x=0, temp;
    for (int i=0; str[i] != '\0'; i++)
    {
        x=1;
        x = x << (str[i]-97);
        temp=(x & hash);
        if (x == (x & hash))
        {
            cout << str[i] << endl;
            return (true);
        }
        hash = x | hash;
    }
    return (false);
}

int main()
{
    char str[] = "abcd";
    cout << dupString(str) << endl;
    return (0);
}