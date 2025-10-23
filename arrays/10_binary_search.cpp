#include <iostream>
using namespace std;

// Binary search things
int binarySearch(int array[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        // (left + right) / 2 is correct as well
        // as long as left + right doesn't give large int.
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int recursive(int array[], int left, int right, int target) {
    // edge case
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;

    if (array[mid] == target) {
        return mid;
    } else if (array[mid] < target) {
        return recursive(array, mid + 1, right, target);
    } else {
        return recursive(array, left, mid - 1, target);
    }
    return -1;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int main() {
    int array[] = {12, 15, 26, 28, 31, 34, 42, 49, 57, 58, 80};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "We're searching from the array: ";
    printArray(array, size);
    cout << "Number to be found is at the index: ";
    cout << binarySearch(array, size, 34);
    cout << "\n\n";

    // testing recursive
    cout << "Searched by recursive binary search: ";
    cout << recursive(array, 0, size - 1, 34);
    cout << "\n\n";
}