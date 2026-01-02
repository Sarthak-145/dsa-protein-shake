#include <iostream>
using namespace std;

// dumb machine which finds something one by one, it's like our class topper,
// anti-lazy but sometimes dumb
int linearSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        // JS has ===, I hope == works here!
        if (target == array[i]) {
            return i;
        }
    }
    // these cpp guys return -1 if nothing works, it's like take something -
    // I've nothing to give
    return -1;
}

int findMax(int array[], int size) {
    // int max = 0; => won't work for -ve numbers so..
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (max < array[i]) {
            max = array[i];
        } 
    }
    return max;
}

int findMin(int array[], int size) {
    // this 1e6 is totally from my JS mind, I don't know whether it works here
    // int min = 1e6;
    int min = array[0];
    for (int i = 0; i < size; i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    return min;
}

int main() {
    int numbers[] = {3, 54, 27, 72, 45, 92, 11, 2, 93, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Maximum number in this array is: " << findMax(numbers, size)
         << "\n";
    cout << "Minimum number in this array is: " << findMin(numbers, size)
         << "\n";
    cout << "92 is in the position: " << linearSearch(numbers, size, 92)
         << "\n";
    return 0;
}