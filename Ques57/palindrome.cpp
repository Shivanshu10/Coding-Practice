#include <iostream>

using namespace std;

bool checkPali(char str[], int size)
{
    int start=0, end=size-1;
    while (start<end)
    {
        if (str[start] != str[end])
        {
            return (false);
        }
        start++;
        end--;
    }
    return (true);
}

int main()
{
    char str[] = "madam";
    cout << checkPali(str, 5) << endl;
    return (0);

}