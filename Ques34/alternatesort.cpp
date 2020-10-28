#include <iostream>
#include <array>
#include <algorithm>

#define SIZE 5

using namespace std;

void AlternateSort(array<int, SIZE> &a)
{
	int left = 0;
	int right = a.size() - 1;
	int n = a.size();

	while (left < right)
	{
		cout << a[right--] << " ";
		cout << a[left++] << " ";
	}

	if (n % 2 != 0)
	{
		cout << a[left];
	}
	cout << endl;
}

int main()
{
	array<int, SIZE> arr = {7, 8, 5, 6, 3};

	sort(arr.begin(), arr.end());

	for (auto a : arr)
	{
		cout << a << endl;
	}

	AlternateSort(arr);

	return (0);
}