#include <iostream>
using namespace std;

// complexity -> Time: O(n^2), space: O(1)
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool isSwapped = false;

        // actual algo -> largest ele gets at the end
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                isSwapped = true;
            }
        }

        // This is for optimization
        if (!isSwapped) {
            // If no swapping in a round, then array is sorted.
            break;
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int main() {
    int numbers[] = {57, 37, 86, 24, 2, 59, 29, 99, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Array we are taking to sort is: ";
    printArray(numbers, size);
    bubbleSort(numbers, size);
    cout << "Sorted array is: ";
    printArray(numbers, size);
}