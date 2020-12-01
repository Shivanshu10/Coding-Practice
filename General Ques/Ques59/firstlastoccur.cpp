#include <iostream>

using namespace std;

int binSearch(int a[], int size, int x)
{
    int start=0, end=size-1, mid;
    while (start <= end)
    {
        mid = start+end/2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            end=mid-1;
        }
        else if(a[mid] < x)
        {
            start=mid+1;
        }
    }
    return (-1);
}

int firstOccur(int a[], int size, int x)
{
    int i=binSearch(a, size, x);
    if (i == -1)
    {
        return (-1);
    }
    while (a[i-1] == x)
    {
        i--;
    }
    return (i);
}

int lastOccur(int a[], int size, int x)
{
    int i=binSearch(a, size, x);
    if (i==-1)
    {
        return -1;
    }
    while (a[i+1] == x)
    {
        i++;
    }
    return (i);
}

int main()
{
    int a[] = {1, 2, 3, 3, 3, 4};
    int first_occur = firstOccur(a, 6, 3);
    int last_occur = lastOccur(a, 6, 3);
    cout << first_occur << " " << last_occur << endl;
    return (0);
}