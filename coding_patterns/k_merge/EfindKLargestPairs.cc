#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> findKLargestPairs(const vector<int> &a, const vector<int> &b, const int &k) {
    struct GreaterSumComparator {
        bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
            return x.first + x.second > y.first + y.second;
        }
    };
    vector<pair<int, int>> minSumHeap;

    for (int ai = 0; ai < a.size() && ai < k; ++ai) {
        for (int bi = 0; bi < b.size() && bi < k; ++bi) {
            if (minSumHeap.size() < k) {
                minSumHeap.emplace_back(a[ai], b[bi]);
                make_heap(minSumHeap.begin(), minSumHeap.end(), GreaterSumComparator());
            } else {
                // if sum of two numbers from two arrays is smaller than the top heap element
                // then there will be no sum higher than top element
                // as the array is sorted in descending order
                if (a[ai] + b[bi] < minSumHeap.front().first + minSumHeap.front().second) {
                    break;
                } else {
                    pop_heap(minSumHeap.begin(), minSumHeap.end(), GreaterSumComparator());
                    minSumHeap.pop_back();
                    minSumHeap.emplace_back(a[ai], b[bi]);
                    make_heap(minSumHeap.begin(), minSumHeap.end(), GreaterSumComparator());
                }
            }
        }
    }

    return minSumHeap;
}

/*
 * Given two sorted arrays in descending order,
 * find ‘K’ pairs with the largest sum where each pair consists of numbers from both the arrays.
 */
int main() {
    auto pairs = findKLargestPairs({9, 8, 2}, {6, 3, 1}, 3);
    for (auto &x: pairs)
        cout << x.first << " " << x.second << endl;
}
