#include <iostream>

using namespace std;

int maxOne(int a[4][4])
{
    int row=0;
    int prev_one=-1;
    for (int i=0; i<4; i++)
    {
        if (a[0][i]==1)
        {
            prev_one=i;
            break;
        }
    }
    for (int i=0; i<4; i++)
    {
        if (prev_one==0)
        {
            return (row);
        }
        if (a[i][prev_one]==1 && a[i][prev_one-1]==1)
        {
            row=i;
            for (int j=i-1; j!=0; j--)
            {
                if (a[i][j]==0)
                {
                    break;
                }
                prev_one=j;
            }
        }
    }
    if (prev_one==-1)
    {
        return (-1);
    }
    return (row);
}

int main()
{
    int Arr[4][4] = {{1, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}};
    cout << maxOne(Arr) << endl;    
    return (0);
}