#include <iostream>
using namespace std;

// problem: Find the max sum of contigious subarray.

// O(n^3) => boomer thing 😂
int maxSubarray(int array[], int size) {
    int maxsum = array[0];

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

int sameButBetter(int array[], int size) {
    int maxsum = array[0];

    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = i; j < size; j++) {
            sum += array[j];
            maxsum = max(sum, maxsum);
        }
    }
    return maxsum;
}

// kadane dude's algo
int sameAndBest(int array[], int size) {
    int maxsum = array[0];
    int currentsum = array[0];

    for (int i = 1; i < size; i++) {
        currentsum += array[i];

        maxsum = max(maxsum, currentsum);

        if (currentsum < 0) {
            currentsum = 0;
        }
    }
    return maxsum;
}

int main() {
    int numbers[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Max sum of adjecent array elements is:\n ";
    cout << maxSubarray(numbers, size) << "\n\n";

    // same but better function
    cout << "Max sum of adjacent array elements is:\n";
    cout << sameButBetter(numbers, size) << "\n\n";

    // testing dude's algo 😎
    cout << "Max sum of adjacent array elements is:\n";
    cout << sameAndBest(numbers, size) << "\n\n";

    // test with another me-made array, cause I've a doubt
    int test[] = {-2, 7, -4, 5, 2, 0, -2, -4};
    int sizetest = sizeof(test) / sizeof(test[0]);
    cout << "Max sum of adjacent array elements is: \n";
    cout << sameAndBest(test, sizetest) << "\n\n";
    // Oh okay, doubt was dumb.
}