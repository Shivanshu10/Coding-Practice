#include <iostream>

using namespace std;

int binsearch(int arr[], int l, int u, int val)
{
    if (l <= u)
    {
        int c = (l + u) / 2;
        if (arr[c] == val)
        {
            return (c);
        }
        else if (arr[c] > val)
        {
            return(binsearch(arr, l, c-1, val));
        }
        else if (val > arr[c])
        {
            return(binsearch(arr, c+1, u, val));
        }
    }
    return (-1);
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    cout << binsearch(arr, 0, 4, 4) << endl;
    return (0);
}