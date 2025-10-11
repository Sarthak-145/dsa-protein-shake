#include <iostream>
#include <string>
using namespace std;

// Strings are actually objects they say, I am reading doc so..
// Like JS, but JS is more objetified 😂

int main() {
    string firstname = "Tyler ";
    string lastname = "Durden";
    string fullname = firstname + lastname;
    // concatenation and append
    cout << fullname << endl;
    cout << firstname.append(lastname) << endl;

    // for length
    cout << lastname.size() << endl;
    cout << lastname.length() << endl;

    // both are somehow same, don't know the fukin point yet
    cout << lastname[1] << endl;
    cout << lastname.at(1) << endl;

    string detail;
    cout << "Tell something weird about you: \n";
    getline(cin, detail);
    cout << "LOL: " << detail;
}
