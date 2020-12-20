#include <iostream>

using namespace std;

void solveTowerofHanoi(int num_disk, char from='A', char aux='B', char to='C') {
    if (num_disk==1) {
        cout << "Move 1 disk from rod " << from << " to " << to << endl;
        return;
    }
    solveTowerofHanoi(num_disk-1, from, to, aux);
    cout << "Move 1 disk from rod " << from << " to " << to << endl;
    solveTowerofHanoi(num_disk-1, aux, from, to);
}

int main() {
    int num_disk;
    cin >> num_disk;
    solveTowerofHanoi(num_disk, 'A', 'B', 'C');
    return (0);
}