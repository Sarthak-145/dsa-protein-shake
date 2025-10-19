#include <iostream>
using namespace std;

int maxSum(int array[], int size, int k) {
    int maxsum = array[0];
    for (int i = 0; i <= size - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += array[j];
        }
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

int maxSumBest(int array[], int size, int k) {
    int windowsum = 0;

    for (int i = 0; i < k; i++) {
        windowsum += array[i];
    }
    int maxsum = windowsum;

    for (int i = k; i < size; i++) {
        windowsum = windowsum - array[i - k] + array[i];
        maxsum = max(maxsum, windowsum);
    }
    return maxsum;
}

void firstNegative(int array[], int size, int k) {
    cout << "First negative value you're looking for in window " << k
         << " is: ";

    for (int i = 0; i <= size - k; i++) {
        bool found = false;
        for (int j = i; j < i + k; j++) {
            if (array[j] < 0) {
                cout << array[j] << " ";
                found = true;
                break;
            }
        }
        if (!found) {
            // no negative number
            cout << 0 << " ";
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    // First boomer method
    int numbers[] = {3, 54, 27, 72, 45, 92, 11, 2, 93, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "The array we are working with is: ";
    printArray(numbers, size);
    cout << "Max sum calc with boomer method is: ";
    cout << maxSum(numbers, size, 3) << "\n\n";

    // with sliding window
    cout << "Max sum calc with sliding window: ";
    cout << maxSumBest(numbers, size, 3);
    cout << "\n\n";

    // for finding negative number in the given array.
    int array[] = {2, -4, 5, 2, 6, -1, 5, 7};
    int arraySize = sizeof(array) / sizeof(array[0]);
    cout << "Array we are working with is: ";
    printArray(array, arraySize);
    cout << "window is sliding by one element at a time, that's why -4 is two "
            "times and -1 is 3 times.\n";
    cout << "Maximum times a number can repeat again is k: Here it is: 3 \n";
    firstNegative(array, arraySize, 3);
    cout << "\n\n";
}