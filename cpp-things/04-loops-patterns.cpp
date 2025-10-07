#include <iostream>
using namespace std;

void pattern_rightAngleTriangle();
void pattern_differentLetters();
void pattern_centerAlign();
int main() {
    // every one of them is working ✅, I've tested function.
    pattern_rightAngleTriangle();
    pattern_differentLetters();
    pattern_centerAlign();
    return 0;
}

void pattern_rightAngleTriangle() {
    int i, j;
    for (i = 10; i > 0; i--) {
        for (j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern_differentLetters() {
    char ch = 65;
    for (int i = 5; i > 0; i--) {
        for (int j = 0; j <= 5 - i; j++) {
            cout << ch;
        }
        cout << endl;
        ch += 1;
    }
}

void pattern_centerAlign() {
    char ch = 65;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5 - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i) - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Future me will add more patterns, if I feel so 🙂‍↕️