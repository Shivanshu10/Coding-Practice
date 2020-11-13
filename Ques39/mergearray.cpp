#include <iostream>

using namespace std;

int* merge(int a[], int sizea, int b[], int sizeb)
{
    int i=0, j=0, k=0;
    int *res = new int[sizea + sizeb];
    while (i<sizea && j<sizeb)
    {
        if (a[i] > b[j])
        {
            res[k++] = b[j];
            j++;
        }
        else if (a[i] < b[j])
        {
            res[k++] = a[i];
            i++;
        }
        else if (a[i] == b[j])
        {
            res[k++] = a[i];
            i++;
            j++;
        }
    }
    for (; i<sizea; i++)
    {
        res[k++] = a[i];
    }
    for (; j<sizeb; j++)
    {
        res[k++] = b[j];
    }
    return (res);
}

int main()
{
    int a[3] = {1, 2, 5};
    int b[5] = {0, 1, 1, 5, 5};
    int* res = merge(a, 3, b, 5);
    for (int i=0; i<8; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return (0);
}