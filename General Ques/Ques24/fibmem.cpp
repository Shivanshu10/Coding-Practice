#include <iostream>

using namespace std;

int arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int fib(int n)
{
    if (n <= 1)
    {
        arr[n] = n;
        return (n);
    }
    else 
    {
        if (arr[n-2] == -1)
        {
            arr[n-2] = fib(n-2);
        }
        if (arr[n-1] == -1)
        {
            arr[n-1] = fib(n-1);
        }
        arr[n] = arr[n-2] + arr[n-1];
        return (arr[n-2] + arr[n-1]);
    }
    return (arr[n-1] + arr[n-2]);
}

int main()
{
    cout << fib(5) << endl;
    return (0);
}