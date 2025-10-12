#include <iostream>
#include <string>

// 2 or 4 bytes
int num = 7;

// double is more precise than float
// float 4 bytes, double 8 bytes
float num2 = 4.8;
double num3 = 4.9;

// we can also use ASCII number if no quotes
char letter = 'S';
// char letter2 = "S"; wtf, it's just doesn't work ("")

// not built in though
std::string name = "Epicurious";

// 1 byte like char
bool isStudent = true;

int main() {
    // boolean reurns 0/1
    std::cout << isStudent << std::endl;
    // sizeof() gives memory space in bytes
    std::cout << sizeof(name) << " bytes";
}

// There's a dude named "auto" which auto assigns data type.
