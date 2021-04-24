#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &arr) {
    out << "[";
    for (int size = arr.size(), i = 0; i < size; ++i)
        out << arr[i] << (i + 1 == arr.size() ? "" : ", ");
    out << "]";
    return out;
}

vector<int> topKFrequent(const vector<int> &arr, int k) {
    unordered_map<int, int> freq;
    for (auto &x: arr)
        freq[x]++;

    struct GreaterFreqCompare {
        bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
            return x.second > y.second;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, GreaterFreqCompare> minHeap;

    for (auto entry: freq) {
        minHeap.push(entry);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        auto tmp = minHeap.top();
        minHeap.pop();
        result.emplace_back(tmp.first);
    }

    return result;
}

/*
 * Given an unsorted array of numbers, find the top ‘K’ frequently occurring numbers in it.
 */
int main() {
    cout << topKFrequent({1, 3, 5, 12, 11, 12, 11}, 2) << endl;
    cout << topKFrequent({5, 5, 12, 11, 3, 11, 11, 11}, 2) << endl;
}
