#include <iostream>

using namespace std;

void rotateOne(int a[], int size)
{
    int temp = a[size-1];
    for (int i=size-1; i!=0; i--)
    {
        a[i] = a[i-1];
    }
    a[0] = temp;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 10, 1, 2, 10, 2, 3};
    rotateOne(arr, 10);
    for (int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return (1);
}