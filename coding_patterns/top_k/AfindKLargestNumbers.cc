#include <bits/stdc++.h>

using namespace std;

vector<int> findKLargestNumbers(const vector<int> &arr, int k) {
    if (k <= 0)
        return {};

    if (arr.size() <= k)
        return arr;

    vector<int> minHeap{arr.begin(), arr.begin() + k};
    make_heap(minHeap.begin(), minHeap.end(), greater<int>());

    for (int i = k; i < arr.size(); ++i) {
        if (arr[i] > minHeap.front()) {
            pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
            minHeap.pop_back();
            minHeap.push_back(arr[i]);
            push_heap(minHeap.begin(), minHeap.end(), greater<int>());
        }
    }

    return minHeap;
}

/*
 * Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
 */
int main() {
    auto topK = findKLargestNumbers({3, 1, 5, 12, 2, 11}, 3);
    for (auto &x: topK)
        cout << x << endl;
}
