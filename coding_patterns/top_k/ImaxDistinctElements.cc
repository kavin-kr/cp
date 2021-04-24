#include <bits/stdc++.h>

using namespace std;

int maxDistinctElements(const vector<int> &arr, int k) {
    if (arr.size() <= k)
        return 0;

    unordered_map<int, int> freq;
    for (auto &x: arr)
        freq[x]++;

    int unique = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto &x: freq) {
        if (x.second > 1)
            minHeap.push(x.second);
        else
            ++unique;
    }

    while (k > 0 && !minHeap.empty()) {
        int top = minHeap.top();
        minHeap.pop();

        k -= top - 1;
        // if duplicates is remaining after k is exhausted
        if (k >= 0)
            ++unique;
    }

    // if k is remaining after all duplicates are removed
    if (k > 0)
        unique -= k;

    return unique;
}

/*
 * Given an array of numbers and a number ‘K’,
 * we need to remove ‘K’ numbers from the array such that we are left with maximum distinct numbers
 */
int main() {
    cout << maxDistinctElements({7, 3, 5, 8, 5, 3, 3}, 2) << endl;
    cout << maxDistinctElements({3, 5, 12, 11, 12}, 3) << endl;
    cout << maxDistinctElements({1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2) << endl;
}
