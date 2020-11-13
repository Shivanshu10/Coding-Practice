#include <iostream>

using namespace std;

void dupsorted(int a[], int size)
{
    int count=0;
    for (int i=0; i<size; i++)
    {
        if (a[i] == a[i+1])
        {
            if (count == 0)
            {
                cout << a[i] << " ";
            }
            count++;           
        }
        else if (count != 0)
        {
            cout << (count+1) << endl;
            count=0;
        }
    }
}

int main()
{
    int a[] = {1, 2, 2, 2, 3, 3, 4};
    dupsorted(a, 6);
    return (0);
}