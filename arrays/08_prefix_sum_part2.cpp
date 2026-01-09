#include <iostream>
#include<climits>
#include <bits/stdc++.h>
using namespace std;

int SubWithSumK(vector<int>& array, int k) {
    unordered_map<int int> freq;
    int count = 0;
    int prefixsum = 0;

    for (int x : array) {
        prefixsum += x;
        int needed = prefixsum - k;

        if (freq.find(needed) != freq.end()) {
            count += freq[needed];
        }
        freq[prefixsum]++;
    }
    return count;
}


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int K;
    cin >> K;

    cout << SubWithSumK(arr, K) << endl;

    return 0;
}









