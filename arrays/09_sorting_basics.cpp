#include <iostream>
using namespace std;

// All these three algos have same space and time complexity
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

void insertionSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

bool isSorted(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int main() {
    cout << "TESTING BUBBLE SORT\n";
    int numbers1[] = {57, 37, 86, 24, 2, 59, 29, 99, 7};
    int size1 = sizeof(numbers1) / sizeof(numbers1[0]);
    cout << "Array we are taking to sort is: ";
    printArray(numbers1, size1);
    bubbleSort(numbers1, size1);
    cout << "Sorted array is: ";
    printArray(numbers1, size1);
    cout << "\n\n";

    // testing selectionSort
    cout << "TESTING SELECTION SORT\n";
    int numbers2[] = {1, 4, 2, 5, 6, 8, 3};
    int size2 = sizeof(numbers2) / sizeof(numbers2[0]);
    cout << "Array we are working with is: ";
    printArray(numbers2, size2);
    selectionSort(numbers2, size2);
    cout << "Sorted array is: ";
    printArray(numbers2, size2);
    cout << "\n\n";

    // testing insertionSort
    cout << "TESTING INSERTION SORT\n";
    int numbers3[] = {3, 2, 5, 7, 4, 8, 1, 9, 6};
    int size3 = sizeof(numbers3) / sizeof(numbers3[0]);
    cout << "Original array is: ";
    printArray(numbers3, size3);
    insertionSort(numbers3, size3);
    cout << "Sorted array is: ";
    printArray(numbers3, size3);
    cout << "\n\n";

    // testing boolean function
    cout << isSorted(numbers1, size1) << endl;
    cout << isSorted(numbers2, size2) << endl;
    cout << isSorted(numbers3, size3) << endl;
}