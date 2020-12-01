#include <iostream>

using namespace std;

int* setUnion(int a[], int sizea, int b[], int sizeb, int &res_size)
{
    int i=0, j=0, k=0, size=0;
    int *res = new int[sizea+sizeb];

    while (i<sizea && j<sizeb)
    {
        if (a[i] > b[j])
        {
            res[k++] = b[j];
            j++;
            size++;
        }
        else if (a[i] < b[j])
        {
            res[k++] = a[i];
            i++;
            size++;
        }
        else if(a[i] == b[j])
        {
            i++;
            j++;
        }
    }
    for (; i<sizea; i++)
    {
        res[k++] = a[i];
        size++;
    }
    for (; j<sizeb; j++)
    {
        res[k++] = b[j];
        size++; 
    }
    int *res1 = new int[size];
    for (i=0; i<size; i++)
    {
        res1[i] = res[i];
    }
    delete [] res;
    res_size=size;
    return (res1);
}

int main()
{
    int a1[3] = {1, 2, 3};
    int b1[3] = {3, 4, 5};
    int size=0;
    int *res = setUnion(a1, 3, b1, 3, size);
    for (int i=0; i<size; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return (0);
}