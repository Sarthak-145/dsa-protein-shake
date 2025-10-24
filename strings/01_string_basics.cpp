#include <iostream>
#include <string>
// this is used for character functions
#include <cctype>
using namespace std;

void stringBasics() {
    string s1 = "Hello";
    string s2("World");
    // idk why but " " isn't working here. Also must char.
    string s3(4, 'D');

    // Ik, I am  not going to see this file again after some time but still.
    cout << "Length of s1 is: " << s1.length() << endl;
    cout << "Another way is: " << s1.size() << endl;
    cout << s3;

    /* There are hell of other things but I am going to skip them cause
       I kinda know them. I'll add once I find some crazy shit */
}

int main() { stringBasics(); }
