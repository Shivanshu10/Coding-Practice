#include <iostream>

using namespace std;

class Array
{
	private:
		int *arr = NULL;
		int size = 0;
	public:
		Array(int a[], int n)
		{
			arr = a;
			size = n;
		}
		void reverse()
		{
			int temp;
			int left = 0;
			int right = size - 1;
			while (left < right)
			{
				temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
				right--;
				left++;
			}
		}
		void disp()
		{
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
};

int main()
{
	int a[] = {1, 2, 3, 4};
	Array arr(a, 4);
	arr.reverse();
	arr.disp();
	return (0);
}