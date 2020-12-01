#include <iostream>

using namespace std;

double taylorseries(int x, int n)
{
    static double q = 1;
    if (n == 0)
    {
        return (1);
    }
    q = (x * q / n + 1);
    return (taylorseries(x, n-1));
}

int main()
{
    cout << taylorseries(2, 15) << cout;
    return (0);
}
