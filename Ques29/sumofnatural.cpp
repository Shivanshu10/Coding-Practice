#include <iostream>

using namespace std;

int sumofnaturalnum(int n)
{
	if (n!=0)
	{
		return(n + sumofnaturalnum(n-1));
	}
	else
	{
		return (0);
	}
}

int main()
{
	int n = 3;
	n = sumofnaturalnum(n);
	cout << n << endl;
	return (0);
}