#include <iostream>

using namespace std;

void ksumsorted(int a[], int size, int k)
{
    int i=0, j=size-1;
    while (i<j)
    {
        if (a[i] + a[j] > k)
        {
            j--;
        }
        else if (a[i] + a[j] < k)
        {
            i++;
        }
        else if (a[i] + a[j]==k)
        {
            cout << a[i] << " " << a[j] << endl;
            i++;
            j--;
        }
    }
}

int main()
{
    int a[] = {1, 2, 4, 6, 8};
    ksumsorted(a, 5, 10);
    return (0);
}