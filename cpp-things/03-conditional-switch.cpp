#include <iostream>
using namespace std;

void compare();
// if else is same as JS
int main() {
    // even float isn't working as 9.8 can't be stored perfectly in binary.
    double g = 9.8;
    if (g > 9.8) {
        cout << "You will fall more abruptly" << endl;
    } else if (g < 9.8) {
        cout << "You'll fall sloooowly" << endl;
    } else {
        cout << "You'll feel like falling on earth 😁" << endl;
    }
    // ternary -> same like JS
    int isRight = (g == 9.8) ? true : false;
    cout << "isRight: " << isRight << endl;

    // switch case
    int yuga = 4;
    switch (yuga) {
        case 1:
            cout << "Satyuga" << endl;
            break;
        case 2:
            cout << "Tretayuga" << endl;
            break;
        case 3:
            cout << "Dwaparyuga" << endl;
            break;
        case 4:
            cout << "Kaliyuga" << endl;
            break;
        default:
            cout << "There are only 4 yugas you dumbazz" << endl;
    }
    compare();
}

// for that binary sotroing problem
#include <cmath>

// if you want to use float and you are stuborn
void compare() {
    float number = 9.8f;
    if (fabs(number - 9.8f) < 1e-6) {
        cout << "This is working!";
    } else {
        cout << "How the fug this isn't working";
    }
}