#include <bits/stdc++.h>

using namespace std;

pair<int, int> smallestRange(const vector<vector<int>> &lists) {
    struct HeapEntry {
        int i, j, val;

        HeapEntry(int i, int j, int val) : i(i), j(j), val(val) {}

        bool operator>(const HeapEntry &x) const {
            return val > x.val;
        }
    };
    priority_queue<HeapEntry, vector<HeapEntry>, greater<HeapEntry>> minHeap;

    int start = 0, end = numeric_limits<int>::max();
    int currMax = numeric_limits<int>::min();
    for (int i = 0; i < lists.size(); ++i)
        if (!lists[i].empty()) {
            minHeap.emplace(i, 0, lists[i][0]);
            currMax = max(currMax, lists[i][0]);
        }

    while (minHeap.size() == lists.size()) {
        HeapEntry tmp = minHeap.top();
        minHeap.pop();

        if (end - start > currMax - tmp.val) {
            start = tmp.val;
            end = currMax;
        }

        if (tmp.j + 1 < lists[tmp.i].size()) {
            minHeap.emplace(tmp.i, tmp.j + 1, lists[tmp.i][tmp.j + 1]);
            currMax = max(currMax, lists[tmp.i][tmp.j + 1]);
        }
    }

    if (end == numeric_limits<int>::max())
        return {-1, -1};
    return {start, end};
}

/*
 * Given ‘M’ sorted arrays, find the smallest range that includes
 * at least one number from each of the ‘M’ lists.
 */
int main() {
    auto range = smallestRange({{1, 5, 8},
                                {4, 12},
                                {7, 8, 10}});
    cout << range.first << " " << range.second << endl;
}
