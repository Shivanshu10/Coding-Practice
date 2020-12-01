#include <iostream>

using namespace std;

void binsearch(int a[4][4], int x, int row)
{
    int r=4, l=0, mid;
    while (r >= l)
	{
		mid = l + (r - l) / 2;
		if (a[row][mid]  == x)
		{
			cout << "Found at " << row << " " << mid << endl;
			return;
		}
		else if (a[row][mid] > x)
		{
            r=mid-1;
		}
        else
        {
            l=mid+1;
        }
	}
	cout << "Not found" << endl;
	return;
}
void search(int a[4][4], int x)
{
    int i, j;
    for (i=0; i<4; i++)
    {
        if (a[i][3] > x)
        {
            break;
        }
        else if (a[i][3] == x)
        {
            cout << "Found at " << i << " 3" << endl;
            return;
        }

    }
    binsearch(a, x, i);
    return;
}

int main()
{
    int a[4][4] = { { 1, 2, 3, 4 }, 
          { 10, 12, 13, 14 }, 
          { 20, 22, 23,24  }, 
          { 30, 32, 33, 34 } };
    search(a, 13); 
    return (0);
}