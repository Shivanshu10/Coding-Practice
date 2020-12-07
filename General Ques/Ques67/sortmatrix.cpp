#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sortMatrix()
{
    int ncol, nrow;
    cin >> ncol;
    cin >> nrow;
    int* arr=new int[ncol*nrow];
    for (int i=0; i<nrow; i++)
    {
        for (int j=0; j<ncol; j++)
        {
            cin >> arr[(i*ncol)+j];
        }
    }

    sort(arr, arr+(ncol*nrow));

    for (int i=0; i<nrow; i++)
    {
        for (int j=0; j<ncol; j++)
        {
            cout << arr[(i*ncol)+j] << "\t"; 
        }
        cout << endl;
    }
}

int main()
{
    sortMatrix();
    return (0);
}