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
		void klargest(int k)
		{
			int temp;
			for (int i=0; i<k; i++)
			{
				for (int j=0; j<size-i-1; j++)
				{
					if (arr[j] > arr[j+1])
					{
						temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
			}
			cout << arr[size - k] << endl;
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
	int a[] = {1, 4, 3, 2};
	Array arr(a, 4);
	arr.klargest(2);
	arr.disp();
	return (0);
}