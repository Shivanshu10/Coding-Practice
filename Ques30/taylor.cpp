#include <iostream>

using namespace std;

double taylorseries(double x, int n)
{
	static double p = 1, q = 1;
	double r;
	if (n == 0)
	{
		return (1);
	}
	r = taylorseries(x, n-1);
	p = p * x;
	q = q * n;
	return (r + p/q);
}

int main()
{
	double n;
	n = taylorseries(2.0, 15);
	cout << n << endl;
	return (0);
}