#include <iostream>
using namespace std;

// This function can be give the length of the non-duplicate values..
// But still duplicate numbers are present at the end of the array.
int removeDuplicates(int array[], int size) {
    int i = 0;

    for (int j = 1; j < size; j++) {
        if (array[j] != array[i]) {
            i++;
            array[i] = array[j];
        }
    }
    return i + 1;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[] = {3, 3, 54, 54, 27, 72, 45, 92, 11, 2, 2, 93, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Actual array: \n";
    printArray(numbers, size);
    cout << "Actual size of the array: " << size << endl;

    cout << "Length of the array after removing duplicates is: ";
    cout << removeDuplicates(numbers, size);
    // This doesn't work as we're not removing any element from the array.
    //  cout << "Array after removing duplicates is: ";
    //  printArray(numbers, size);
}