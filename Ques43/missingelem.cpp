#include <iostream>

using namespace std;

void missingElem(int a[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=a[i]; j<a[i+1]-1; j++)
        {
            cout << (j+1) << " is missing" << endl;
        }
    }
}

int main()
{
    int a[] = {1, 2, 4, 5, 7, 9, 100};
    missingElem(a, 7);
    return (0);
}