#include <iostream>
#include <string>
using namespace std;

// also avoid using namespace std cause it's like importing
// import http from 'http' and using just createServer.

// there's no array.push() here, these guys use vectors for dynamic arrays.
int main() {
    // we can emit declaring size as well
    string avengers[4] = {"thor", "hulk", "iron man", "wanda"};
    int numbers[5] = {2, 5, 7, 3, 9};

    // traversal
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << "\n";
    }

    // this is kind of forEach method from JS
    for (string avenger : avengers) {
        cout << avenger << "\n";
    }

    // alone sizeof() gives size in bytes (as already seen, but still)
    cout << "Length of the array avengers is: "
         << sizeof(avengers) / sizeof(avengers[0]);

    // So in place of i <= 4 and those things, we should use length of array
    // cause NO HARCODING!
}

// imrovements :
// 1. remove hadcoded value from loops
// 2. remove using namespace std and make a code clean again
