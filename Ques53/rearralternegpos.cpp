#include <iostream>

using namespace std;

void rearr_negpos_alter(int a[], int size)
{
    int pos=-1, neg=size, temp;
    for (int i=0; i<size; i++)
    {
        if (a[i] >= 0 && i%2==0)
        {
            pos++;
            temp=a[pos];
            a[pos]=a[i];
            a[i]=temp;
            i++;
        }
        else if (a[i] < 0 && i%2!=0)
        {
            neg--;
            temp=a[neg];
            a[neg]=a[i];
            a[i]=temp;
            i++;
        }
    }
}

int main()
{
    int a[] = {-1, -2, 4};
    rearr_negpos_alter(a, 3);
    for (int i=0; i<3; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return (0);
}