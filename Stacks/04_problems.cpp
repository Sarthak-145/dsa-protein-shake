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

// Daily Temperatures – Given [73,74,75,71,69], return [1,1,0,0,0] (days to wait for warmer temp)
vector<int> waitForWarmerDay(vector<int>& temp) {
    vector<int> result(temp.size(), 0);
    stack<int> st;

    for (int i=0; i< temp.size(); i++) {
        while (!st.empty() && temp[i] > temp[st.top()]) {
            int top = st.top();
            st.pop();
            result[top] = i - top;
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

    vector<int> nextWarmer = waitForWarmerDay(nums);
    cout << "next warmer day will be after 'n' days: ";
    for (int x: nextWarmer) {
        cout << x << " ";
    }
    cout << "\n\n";
}