#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool validBrackets(const string& str) {
    stack<char> st;
    for (int i=0; i< str.length(); i++) {
        char c = str[i];
        
        if (c == '(' || c == '[' || c=='{') {
            st.push(c);
        }
        else {
            if (st.empty()) return false;
            char top = st.top();
            
            // I am not using hashmaps cause it's complication rn
            if (c ==')' && top != '(') return false;
            if (c ==']' && top != '[') return false;
            if (c =='}' && top != '{') return false;
            st.pop();
        }
    }
    if (st.empty()) return true;
    else return false;
}

int main() {
    string str;
    cout << "Give some brckets input: ";
    cin >> str;
    if (validBrackets(str)) {
        cout << "The bracket closing seq is right!" << "\n";
    } else {
        cout << "Brckets aren't closed properly." << "\n";
    }
}