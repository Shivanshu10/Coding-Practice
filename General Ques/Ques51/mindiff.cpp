#include <iostream>

using namespace std;

int getMinDiff(int a[], int size, int k)
{
    int max = a[0], min = a[0], max_index=0, min_index=0;
    for (int i=0; i<size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            max_index = i;
        }
        else if (a[i] < min)
        {
            min = a[i];
            min_index = i;
        }
    }
    return -((a[min_index] + k) - (a[max_index] - k));
}

int main()
{

    int a[] = {1, 5, 8, 10};
    cout << getMinDiff(a, 4, 2) << endl;
    return (0);
}