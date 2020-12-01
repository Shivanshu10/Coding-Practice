#include <iostream>

using namespace std;

int power(int x, int y)
{
	if (y != 0)
	{
		return(x * power(x, y-1));
	}
	else
	{
		return (1);
	}
}

int main()
{
	int c = power(2, 3);
	cout << c << endl;
	return (0);
}