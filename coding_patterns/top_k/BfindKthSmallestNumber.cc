#include <bits/stdc++.h>

using namespace std;

int findKthSmallestNumber(const vector<int> &arr, const int k) {
    if (k <= 0 || k > arr.size())
        throw invalid_argument("Constraint: k > 0 or k <= arr.size(). "
                               "But k: " + to_string(k) + ", arr.size: " + to_string(arr.size()));

    priority_queue<int> maxHeap(arr.begin(), arr.begin() + k);

    for (int i = k; i < arr.size(); ++i)
        if (arr[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }

    return maxHeap.top();
}

/*
 * Given an unsorted array of numbers, find Kth smallest number in it.
 * Please note that it is the Kth smallest number in the sorted order, not the Kth distinct element
 */
int main() {
    cout << findKthSmallestNumber({1, 5, 12, 2, 11, 5}, 3) << endl;
    cout << findKthSmallestNumber({1, 5, 12, 2, 11, 5}, 4) << endl;
    cout << findKthSmallestNumber({5, 12, 11, -1, 12}, 3) << endl;
}
