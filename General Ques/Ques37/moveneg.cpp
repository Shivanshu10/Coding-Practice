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
		void moveneg()
        {
            int negpos = 0, temp;
            for (int i=0; i<size; i++)
            {
                if (arr[i] < 0)
                {
					if (i != negpos)
					{
						temp = arr[i];
						arr[i] = arr[negpos];
                		arr[negpos] = temp;
					}
					negpos++;
				}
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

	int a[] = {1, 4, -3, 2, -1, 2, -5, -8};
	Array arr(a, 8);
	arr.moveneg();
	arr.disp();
	return (0);
}