#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerIdx(vector<int>& nums) {
    stack<int> st;
    vector<int> nse(nums.size(), -1);

    for (int z = 0; z < nums.size(); z++) {
        while (!st.empty() && nums[z] < nums[st.top()]) {
            int top = st.top();
            st.pop();
            nse[top] = z;
        }
        st.push(z);
    }
    return nse;
}

vector<int> previousSmallerIdx(vector<int>& nums) {
    stack<int> st;
    vector<int> pse(nums.size(), -1);

    for (int i=0; i< nums.size(); i++) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            st.pop();
        }
        if (!st.empty()) {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

int main() {
    vector<int> nums = {10, 2, 5, 4};
    vector<int> result = nextSmallerIdx(nums);
    cout << "Array containing indices of next smaller element is: ";
    for (int x: result) {
        cout << x << " ";
    }
    cout << "\n\n";

    vector<int> result2 = previousSmallerIdx(nums);
    cout << "Array containing indices of previous smaller element is: ";
    for (int x: result2) {
        cout << x << " ";
    }
    cout << "\n\n";
}