#include <iostream>
using namespace std;

// less space complexity [O(1)] => they call it two pointers if I'm not wrong
void reverse(int array[], int start, int end) {
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

// let array = {1, 2, 3, 4, 5} If d = 2; rotate by 2
// first => {2, 1, 3, 4, 5}
// second => {2, 1, 5, 4, 3}
// third => {3, 4, 5, 1, 2}
void rotateLeft(int array[], int size, int d) {
    d = d % size;

    reverse(array, 0, d - 1);
    reverse(array, d, size - 1);
    reverse(array, 0, size - 1);
}

void rotateRight(int array[], int size, int d) {
    d = d % size;

    reverse(array, 0, size - 1);
    reverse(array, 0, d - 1);
    reverse(array, d, size - 1);
}

void rotateLeftByOne(int array[], int size) {
    int temp = array[0];
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = temp;
}
void rotateRightByOne(int array[], int size) {
    int temp = array[size - 1];
    // direction of the loop matters, first one wasn't working!
    for (int i = size - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = temp;
}

// yup, can't just console.log()!
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[] = {3, 54, 27, 72, 45, 92, 11, 2, 93, 34};
    int size = sizeof(array) / sizeof(array[0]);
    rotateLeft(array, size, 2);
    cout << "rotated array is: ";
    printArray(array, size);
    cout << endl;

    rotateRight(array, size, 2);
    cout << "rerotated array is: ";
    printArray(array, size);
    cout << endl;
    // By doing rotation and rerotation we get the exact same array.

    // now just rotate by one
    rotateLeftByOne(array, size);
    cout << "Array rotated by one: ";
    printArray(array, size);
    cout << endl;
    rotateRightByOne(array, size);
    cout << "Array after rotating right by one (original array): ";
    printArray(array, size);
}