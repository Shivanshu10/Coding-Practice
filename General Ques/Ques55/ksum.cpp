#include <iostream>

using namespace std;

void ksum(int a[], int size, int k)
{
    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (k - a[i] == a[j])
            {
                cout << a[i] << " " << a[j] << endl;
            }
        }
    }
}

int main()
{
    int a[] = {1, 2, 4, 5, 0, 5, 4, 5, 2, 3};
    ksum(a, 10, 5);
    return (0);
}