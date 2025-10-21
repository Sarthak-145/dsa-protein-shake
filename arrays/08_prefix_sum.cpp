#include <iostream>
using namespace std;

void prefixArray(int array[], int prefix[], int size) {
    prefix[0] = array[0];

    for (int i = 1; i < size; i++) {
        prefix[i] = prefix[i - 1] + array[i];
    }
}

// sum of array elements from prefixArray, with O(1) space complexity
int sumFromPrefix(int prefix[], int start, int end) {
    if (start == 0) {
        return prefix[end];
    }

    return prefix[end] - prefix[start - 1];
}

int findEquiIndex(int array[], int size) {
    int totalSum = 0;
    for (int i = 0; i < size; i++) {
        totalSum += array[i];
    }

    int leftsum = 0;

    for (int i = 0; i < size; i++) {
        // Bug -> wasn't subtracting array[i] to calculate rightsum!
        int rightsum = totalSum - leftsum - array[i];

        if (leftsum == rightsum) {
            cout << "Equillibrium found! It's at index: " << i << "\n";
            return 0;
        }
        // Also updating leftsum is important.
        leftsum += array[i];
    }
    cout << "Equillibrium doesn't exist!\n";
    return -1;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Array we are working with is: ";
    printArray(numbers, size);
    int prefix[size];
    prefixArray(numbers, prefix, size);
    cout << "Prefix array is: ";
    printArray(prefix, size);

    // testing sum from prefix function
    cout << "Sum of elemtns from index 1 to 4 is: "
         << sumFromPrefix(prefix, 1, 4) << "\n\n";

    // testing equillibrium function
    int equiArray[] = {1, 2, 3, 4, 6};
    int equiSize = sizeof(equiArray) / sizeof(equiArray[0]);
    findEquiIndex(equiArray, equiSize);
}