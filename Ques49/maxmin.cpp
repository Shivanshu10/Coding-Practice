#include <iostream>

using namespace std;

void maxmin(int a[], int size)
{
    int max=a[0], min=a[0];
    for (int i=0; i<size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}
int main()
{
    int a[] = {2, 3, 4, 1, 3 ,4 ,5 ,6 ,7};
    maxmin(a, 9);
    return (0);
}