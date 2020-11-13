#include <iostream>

using namespace std;

void dupunsorted(int a[], int size)
{
    int count;
    bool found;
    for (int i=0; i<size; i++)
    {
        count = 1;
        found = false;
        for (int j=i+1; j<size; j++)
        {
            if (a[i]==a[j] && a[j]!=-1)
            {
                a[j] = -1;
                count++;
                found = true;
            }
        }
        if (found)
        {
            cout << a[i] << " " << count << endl;
        }
    }
}

int main()
{
    int a[] = {5, 2, 1, 4, 5};
    dupunsorted(a, 5);
    return (0);
}