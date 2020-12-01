#include <iostream>

using namespace std;

void maxsumsubarray(int a[], int size)
{
    int mtn, meh, start=0, end;
    for (int i=0; i<size; i++)
    {
        if (i == 0)
        {
            mtn = a[0];
            start = 0;
        }
        else
        {
            if (mtn + a[i] < a[i])
            {
                if (mtn + a[i] > mtn)
                {
                    start = i;
                    end = i;
                }
                mtn = a[i];
            }
            else if (mtn + a[i] > a[i])
            {
                if (mtn + a[i] > mtn)
                {
                    mtn += a[i];
                    end++;
                }
                mtn += a[i];
            }
        }
    }
    cout << start << " " << end << endl;
}
int main()
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxsumsubarray(a, 9);
    return (0);
}