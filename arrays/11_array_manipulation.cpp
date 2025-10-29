#include <iostream>
using namespace std;

void mergeSortedArray(int array1[], int size1, int array2[], int size2,
                      int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            result[k++] = array1[i++];
        } else {
            result[k++] = array2[j++];
        }
    }

    while (i < size1) {
        result[k++] = array1[i++];
    }

    while (j < size2) {
        result[k++] = array2[j++];
    }
}

int intersection(int array1[], int size1, int array2[], int size2,
                 int result[]) {
    int k = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (array1[i] == array2[j]) {
                bool isAlreadyAdded = false;
                for (int z = 0; z < k; z++) {
                    if (result[z] == array1[i]) {
                        isAlreadyAdded = true;
                        break;
                    }
                }
                if (!isAlreadyAdded) {
                    result[k++] = array1[i];
                }
                break;
            }
        }
    }
    return k;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int main() {
    int array1[] = {1, 3, 5, 7};
    int array2[] = {2, 4, 6, 8};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    cout << "Two array are \n";
    cout << "First array: ";
    printArray(array1, size1);
    cout << "Second array: ";
    printArray(array2, size2);
    int result[size1 + size2];
    mergeSortedArray(array1, size1, array2, size2, result);
    cout << "After merge: ";
    printArray(result, size1 + size2);
    cout << "\n\n";

    // testing intersection fucntion
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {1, 3, 7, 8, 4};
    int sz1 = sizeof(arr1) / sizeof(arr1[0]);
    int sz2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "commom elements are: ";
    int result2[min(sz1, sz2)];
    int intersectionSize = intersection(arr1, sz1, arr2, sz2, result2);
    printArray(result2, intersectionSize);
}