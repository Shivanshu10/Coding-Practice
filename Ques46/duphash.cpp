#include <iostream>

using namespace std;

void dupHash(int a[], int size)
{
    int max=a[size-1], min=a[0];
    int *hash = new int[(max-min)+1];
    for (int i=0; i<size; i++)
    {
        hash[a[i]-min]++;
    }
    for (int i=0; i<(max-min)+1; i++)
    {
        if (hash[i] > 1)
        {
            cout << (i+min) << " " << hash[i] << endl; 
        }
    }
}

int main()
{
    int a[] = {1, 2, 2, 3, 4, 5, 5, 8, 10};
    dupHash(a, 9);
    return (0);
}