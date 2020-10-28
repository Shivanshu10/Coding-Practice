#include <iostream>

using namespace std;

void towerofhanoi(int n, int A, int B, int C)
{
    // n is number of disks
    // A is tower1 that is from tower
    // B is tower2 that is auxillary tower
    // C is tower3 that is to tower

    if (n > 0)
    {
        towerofhanoi(n-1, A, C, B);
        cout << "from " << A << " to " << C << endl;
        towerofhanoi(n-1, B, A, C);
    }
}

int main()
{
    towerofhanoi(3, 1, 2, 3);
    return (0);
}