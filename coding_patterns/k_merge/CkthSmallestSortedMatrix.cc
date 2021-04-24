#include <bits/stdc++.h>

using namespace std;

int kthSmallestSortedMatrix(const vector<vector<int>> &mat, const int k) {
    struct HeapEntry {
        int i, j, val;

        HeapEntry(int i, int j, int val) : i(i), j(j), val(val) {}

        bool operator>(const HeapEntry &x) const {
            return val > x.val;
        }
    };
    priority_queue<HeapEntry, vector<HeapEntry>, greater<HeapEntry>> minHeap;

    for (int i = 0; i < mat.size(); ++i) {
        if (!mat[i].empty())
            minHeap.emplace(i, 0, mat[i][0]);
    }

    for (int count = 1; !minHeap.empty() && count < k; ++count) {
        HeapEntry tmp = minHeap.top();
        minHeap.pop();

        if (tmp.j + 1 < mat[tmp.i].size())
            minHeap.emplace(tmp.i, tmp.j + 1, mat[tmp.i][tmp.j + 1]);
    }

    return minHeap.empty() ? -1 : minHeap.top().val;
}

/*
 * Given an N * NN∗N matrix where each row and column is sorted in ascending order,
 * find the Kth smallest element in the matrix.
 */
int main() {
    vector<vector<int>> mat = {{2, 6, 8},
                               {3, 7, 10},
                               {5, 8, 11}};

    cout << kthSmallestSortedMatrix(mat, 5) << endl;
}
