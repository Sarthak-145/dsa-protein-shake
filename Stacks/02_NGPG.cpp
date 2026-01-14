#include<iostream>
#include<stack>
#include <vector>
using namespace std;

vector<int> nextGreater(vector<int>& nums) {
    stack<int> st;
    vector<int> ngeNums(nums.size(), -1);
    st.push(0);
    for (int i=1; i < nums.size(); i++) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            int top = st.top();
            st.pop();
            ngeNums[top] = nums[i];
        } 
        st.push(i);
    }   
    return ngeNums;
} 

int main() {
    vector<int> nums = {4,5,2,10};
    vector<int> result = nextGreater(nums);
    cout << "Next greater element array of the given array is: ";
    for (int n: result) {
        cout << n << " ";
    }
    cout << "\n\n";
}