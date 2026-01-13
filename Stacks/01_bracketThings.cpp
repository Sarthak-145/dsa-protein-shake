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

int totalValidBrackets(const string& str) {
    stack<int> st;
    int mxlength = 0;
    st.push(-1);
    for (int i =0; i < str.length(); i++) {
        if (str[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                mxlength = (i - st.top()) > mxlength ? (i - st.top()) : mxlength;
            }
        }
    }
    return mxlength;
}

int leftOverBrackets(const string& str) {
    stack<char> st;
    for (int i=0; i< str.length(); i++) {
        char c = str[i];
        if (c == '(') st.push(c);
        else {
            if (st.empty()) st.push(c);
            else st.pop();
        }
    }
    return st.size();
}

int main() {
    // string str;
    // cout << "Give some brckets input: ";
    // cin >> str;
    // if (validBrackets(str)) {
    //     cout << "The bracket closing seq is right!" << "\n";
    // } else {
    //     cout << "Brckets aren't closed properly." << "\n\n";
    // }

    cout << "Maximum valid bracket length of the string is: " << totalValidBrackets("))(())()))") << "\n\n";
    cout << "Number of brackets required to make a string valid: "<< leftOverBrackets("(()()))()") << "\n\n";
}