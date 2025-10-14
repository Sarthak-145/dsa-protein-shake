#include <iostream>
using namespace std;

// problem: Find the max sum of contigious subarray.

// O(n^3) => boomer thing 😂
int maxSubarray(int array[], int size) {
    int maxsum = -1e6;

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += array[k];
            }
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

int main() {
    int numbers[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Max sum of adjecent array elements is:\n ";
    cout << maxSubarray(numbers, size);
}