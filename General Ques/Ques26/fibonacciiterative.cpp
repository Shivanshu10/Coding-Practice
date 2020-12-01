#include <iostream>

using namespace std;

int fib(int n)
{
    int res = 0, t0, t1, temp;
    for (int i = 0; i <= n; i++)
    {
        if (i < 2)
        {
            t0 = res;
            res += i;
            t1 = res;
            continue;
        }
        temp = res;
        res = t0 + t1;
        t0 = temp;
        t1 = res;
    }
    return (res);
}

int main()
{
    cout << fib(5) << endl;
    return (0);
}