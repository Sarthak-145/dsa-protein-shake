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

// move all zeroes at the end maintaining the remaining order as it is.
void moveZeroes(int array[], int size) {
    int i = 0;
    for (int j = 0; j < size; j++) {
        if (array[j] != 0) {
            array[i] = array[j];
            i++;
        }
    }

    while (i < size) {
        array[i] = 0;
        i++;
    }
}

// Give indices of two ints when sum is given (twosum they say)
bool twoSome(int array[], int size, int target, int &firstIndex,
             int &secondIndex) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int sum = array[left] + array[right];
        if (sum == target) {
            firstIndex = left;
            secondIndex = right;
            return true;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

int maxWater(int array[], int size) {
    int left = 0;
    int right = size - 1;
    int maxArea = 0;

    while (left < right) {
        int width = right - left;
        int height = min(array[left], array[right]);

        int area = width * height;
        maxArea = max(area, maxArea);

        if (array[left] < array[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
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
    cout << removeDuplicates(numbers, size) << endl << endl;
    // This doesn't work as we're not removing any element from the array.
    //  cout << "Array after removing duplicates is: ";
    //  printArray(numbers, size);

    // for moveZeroes function
    cout << "This is for moving zeroes function: \n";
    int random[] = {12, 0, 43, 56, 29, 0, 38, 0, 3};
    int sizeRandom = sizeof(random) / sizeof(random[0]);
    cout << "Original array is: ";
    printArray(random, sizeRandom);

    moveZeroes(random, sizeRandom);
    cout << "After moving all the zeroes to the end: ";
    printArray(random, sizeRandom);
    cout << "\n\n";

    // testing twoSum function
    int firstIndex, secondIndex;
    int numbers3[] = {2, 4, 5, 7, 9, 26, 27, 32, 46, 57, 68, 72, 99};
    int size3 = sizeof(numbers3) / sizeof(numbers3[0]);
    cout << "We are working with this array: ";
    printArray(numbers3, size3);
    twoSome(numbers3, size3, 53, firstIndex, secondIndex);
    cout << "First index is: " << firstIndex << "\n";
    cout << "Second index is: " << secondIndex << "\n\n";

    // testing maxArea function
    // Array has been copied cause I want to test answer as well!
    int heightArray[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int sizeHeight = sizeof(heightArray) / sizeof(heightArray[0]);
    cout << "Array we're working with is: ";
    printArray(heightArray, sizeHeight);
    cout << "Max water which can be accomodated is: ";
    cout << maxWater(heightArray, sizeHeight);
}