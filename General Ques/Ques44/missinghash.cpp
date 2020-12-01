#include <iostream>

using namespace std;

void findMissing(int a[], int size, int max, int min)
{
    int *hash_table = new int[(max-min)+1];
    for (int i=0; i<size; i++)
    {
        hash_table[(a[i]-min)]+=1;
    }
    for (int i=0; i<(max-min)+1; i++)
    {
        if (hash_table[i] == 0)
        {
            cout << (i+min) << " is missing" << endl;
        }
    }
}

int main()

{
    int a[] = {2, 4, 4, 5, 12, 16, 20};
    findMissing(a, 7, 20, 2);
    return (0);
}