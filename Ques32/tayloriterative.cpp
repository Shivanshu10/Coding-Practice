#include <iostream>

using namespace std;

double taylorseries(double x, int n)
{
    double q = 1;
    for (int i = n; i > 0; i--)
    {
        q = 1 + x * q / i;
    }
    return (q);
}

int main()
{
    cout << taylorseries(2, 15) << endl;
    return (0);
}