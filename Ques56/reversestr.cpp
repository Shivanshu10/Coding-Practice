#include <iostream>

using namespace std;

void reverseStr(char str[], int size)
{
    int start=0, end=size-1;
    char c;
    while (start < end)
    {
        c = str[start];
        str[start] = str[end];
        str[end] = c;
        start++;
        end--;
    }   
}

int main()
{
    char str[] = "hello world";
    reverseStr(str, 11);
    for (int i=0; i<11; i++)
    {
        cout << str[i];
    }
    cout << endl;
    return (0);
}