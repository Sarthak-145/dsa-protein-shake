#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// given daily prices, check how many previous days the price was less than today.
vector<int> stockSpan(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    stack<int> st;

    for (int i=0; i<n; i++) {
        while (!st.empty() && nums[i] >= nums[st.top()]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] =  i - st.top();
        } else {
            result[i] = i + 1;
        }
        st.push(i);
    }
    return result;
}

int main() {
    vector<int> nums = {10, 2, 4, 5};
    vector<int> result = stockSpan(nums);

    cout << "result array is: ";
    for (int x: result) {
        cout << x << " ";
    } 
    cout << "\n\n";
}