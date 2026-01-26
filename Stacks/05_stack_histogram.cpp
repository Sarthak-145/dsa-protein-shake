#include<iostream>
#include<stack>
#include<vector>
using namespace std;


//this question is most satisfying in stacks.
int maxAreaHistogram(vector<int>& heights) {
    //we add one element cause we want all the elements to be popped.
    //last 0, will satisfy the while loop for all the reamining elements 
    heights.push_back(0);
    int size = heights.size();

    int maxarea = 0;
    stack<int> st;

    for (int i=0; i < size; i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            
            int rightmin = i;
            int leftmin = st.empty() ? -1 : st.top();
            int width = rightmin - leftmin - 1;

            maxarea = max(maxarea, height * width);
        }
        st.push(i);
    }
    return maxarea;
}

int maxRectMatrix(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int result = 0;

    vector<int> heights(cols, 0);

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            // careful and use same data type in comparison and decalration. 
            heights[j] = matrix[i][j] == '1'? heights[j] + 1 : 0; 
        }
        // take max of all rows 
        result = max(result, maxAreaHistogram(heights));
    }
    return result;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Max area of this histogram is: " << maxAreaHistogram(heights) << "\n\n";

    vector<vector<char>> matrix = {
        {'1', '1', '1'},
        {'1', '1', '1'}
    };

    cout << "Max rectangle of this matrix: " << maxRectMatrix(matrix) << "\n\n";
}