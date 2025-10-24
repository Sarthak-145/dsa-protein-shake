#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    int start = 0;
    int end = s.length() - 1;

    while (start <= end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

string reverseString(string s) {
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}

int main() {
    // First function -> tested ✅
    //  string word;
    //  cout << "Type a word to check whether it is pallindrome or not: ";
    //  cin >> word;
    //  cout << "\n";
    //  if (isPalindrome(word) == true) {
    //      cout << "The string provided is a pallindrome!\n";
    //  } else {
    //      cout << "It is not a pallindrome!\n";
    //  }
    //  cout << "\n\n";

    // testing reverse string function
    // taking user input isn't hard so skipping it.
    cout << reverseString("sarthak");
    cout << "\n\n";
}