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

// Opposite of bubble, find smallest number and place it at the start.
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minValue = i;

        for (int j = i; j < size; j++) {
            if (array[j] < array[minValue]) {
                minValue = j;
            }
        }
        if (minValue != i) {
            int temp = array[i];
            array[i] = array[minValue];
            array[minValue] = temp;
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
    int numbers1[] = {57, 37, 86, 24, 2, 59, 29, 99, 7};
    int size1 = sizeof(numbers1) / sizeof(numbers1[0]);
    cout << "Array we are taking to sort is: ";
    printArray(numbers1, size1);
    bubbleSort(numbers1, size1);
    cout << "Sorted array is: ";
    printArray(numbers1, size1);

    // testing selectionSort
    int numbers2[] = {1, 4, 2, 5, 6, 8, 3};
    int size2 = sizeof(numbers2) / sizeof(numbers2[0]);
    cout << "Array we are working with is: ";
    printArray(numbers2, size2);
    selectionSort(numbers2, size2);
    cout << "Sorted array is: ";
    printArray(numbers2, size2);
}