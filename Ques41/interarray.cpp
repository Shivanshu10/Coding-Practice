#include <iostream>

using namespace std;

int* inter(int a[], int sizea, int b[], int sizeb, int& res_size)
{
    int i=0, j=0, k=0, size=0;
    int* res = new int[(sizea > sizeb)?sizea:sizeb];
    while (i<sizea && j<sizeb)
    {
        if (a[i] == b[j])
        {
            res[k++] = a[i];
            i++;
            j++;
            size++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
    }
    int* res1 = new int[size];
    for (int i=0; i<size; i++)
    {
        res1[i] = res[i];
    }
    delete [] res;
    res_size = size;
    return (res1);
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[6] = {1, 2, 3, 7, 8, 9};
    int res_size;
    int* res = inter(a, 5, b, 6, res_size);
    for (int i=0; i<res_size; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return (0);
}