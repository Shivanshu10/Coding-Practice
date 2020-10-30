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
			int temp, index = 0, n = size;
			for (int j=0; j<k; j++)
			{
				temp = arr[0];
				for (int i=0; i<n; i++)
				{
					if (arr[i] > temp)
					{
						temp = arr[i];
						index = i;
					}
				}
				temp = arr[index];
				arr[index] = arr[n-1];
				arr[n-1] = temp;
				n--; 
			}
			cout << arr[index] << endl;
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
	arr.klargest(3);
	arr.disp();
	return (0);
}