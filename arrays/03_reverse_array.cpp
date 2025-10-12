#include <iostream>
using namespace std;

/*This one has O(n) space complexity, we use one more copy for just reversing
the array.
//Hiring a employee for giving you gymshoes everytime you go to the gym -> yup,
for nothing*/
void normalReverseArray(int array[], int size) {
    // int tempArray[size];  //this thing works with gcc but not standard cpp.
    int* tempArray = new int[size];
    for (int i = 0; i < size; i++) {
        tempArray[i] = array[size - i - 1];
    }

    // for copying in main array
    for (int i = 0; i < size; i++) {
        array[i] = tempArray[i];
    }
    delete[] tempArray;  // manual memory deallocation, feels too cpp-ish 😂
}

// this one has O(1) space complexity, basically we're using a signel array so
// less memory use.
void crazyReverseArray(int array[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

// just for printing array, can't just log to the console, crazy language.

/* you can't pass just an array to the printArray and calculate sizeof that
   array later. I don't know why ?*/
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    // So difficult to type random numbers, just copied from prev file 😭
    int numbers[] = {3, 54, 27, 72, 45, 92, 11, 2, 93, 34};
    normalReverseArray(numbers, sizeof(numbers) / sizeof(numbers[0]));
    cout << "Reverse of the array is: ";
    printArray(numbers, sizeof(numbers) / sizeof(numbers[0]));

    crazyReverseArray(numbers, sizeof(numbers) / sizeof(numbers[0]));
    cout << "Original array after double reversing it: ";
    printArray(numbers, sizeof(numbers) / sizeof(numbers[0]));
    return 0;
}