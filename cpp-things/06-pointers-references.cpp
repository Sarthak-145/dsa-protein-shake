#include <iostream>
#include <string>
using namespace std;

// This is actually hot topic I feel, not in JS
int main() {
    string food = "chicken";
    //& gives memory address of the variable
    cout << &food << endl;  // gives address

    // so this line -> ptr variable stores the memory address of food variable
    string* ptr = &food;
    cout << ptr << endl;  // gives address

    // when we use * and pointer it gives value -> like -ve * -ve = + ve thing.
    // They call this dereferencing
    cout << *ptr << endl;  // gives chicken 👌

    // as *ptr gives value, we can fukin change it!
    *ptr = "salmon";
    cout << food << endl;
    cout << *ptr << endl;

    // this guy is referencing, it's like giving nickname
    // Now you can use either drink ro liquid for accessing water value.
    string drink = "water";
    string& liquid = drink;
    cout << drink << endl;
    cout << liquid << endl;
}