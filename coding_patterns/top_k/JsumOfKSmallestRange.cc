#include <bits/stdc++.h>

using namespace std;

int sumOfKSmallestRange(const vector<int> &arr, const int k1, const int k2) {
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

    for (int i = 0; !minHeap.empty() && i < k1; ++i)
        minHeap.pop();

    int sum = 0;
    for (int i = 0; !minHeap.empty() && i < k2 - k1 - 1; ++i) {
        sum += minHeap.top();
        minHeap.pop();
    }

    return sum;
}

/*
 * Given an array, find the sum of all numbers between the K1’th and K2’th smallest elements of that array.
 */
int main() {
    cout << sumOfKSmallestRange({1, 3, 12, 5, 15, 11}, 3, 6) << endl;
    cout << sumOfKSmallestRange({3, 5, 8, 7}, 1, 4) << endl;
}
