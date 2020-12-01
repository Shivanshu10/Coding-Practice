#include <iostream>

using namespace std;

int pairSumk(int a[], int size, int min, int max, int k)
{
    int count = 0;
    int *hash = new int[(max - min) + 1];
    for (int i=0; i<size; i++)
    {
        hash[a[i]-min]++;
    }
    for (int i=0; i<size; i++)
    {
        if (hash[k-a[i]-min] != 0)
        {
            count++;
        }
    }
    return (count/2);
}

int main()
{
    int a[] = {-3, 1, 7, -1, 5};
    cout << pairSumk(a, 5, -1, 7, -10) << endl;
    return (0);
}