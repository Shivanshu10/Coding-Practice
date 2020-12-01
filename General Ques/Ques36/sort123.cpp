#include <iostream>

using namespace std;

void sort123(int arr[], int size)
{
    int freq[3] = {0, 0, 0};
    int temp=0;
    for (int i=0; i<size; i++)
    {
        freq[arr[i]] += 1;
    }

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<freq[i]; j++)
        {
            arr[temp++] = i;
        }
    }
}

int main()
{
    int arr[5] = {0,1,0,0,2};
    sort123(arr, 5);
    for (int i=0; i<5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
