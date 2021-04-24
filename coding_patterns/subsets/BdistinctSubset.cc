#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &arr) {
    out << "[";
    for (int i = 0, size = arr.size(); i < size; ++i)
        out << arr[i] << (i == size - 1 ? "" : ", ");
    out << "]";
    return out;
}

ostream &operator<<(ostream &out, const vector<vector<int>> &arr) {
    out << "[" << (!arr.empty() ? "\n" : "");
    for (const auto &i : arr)
        out << "    " << i << "\n";
    out << "]";
    return out;
}

vector<vector<int>> distinctSubset(const vector<int> &arr) {
    vector<vector<int>> subset;
    sort(subset.begin(), subset.end());

    subset.emplace_back();
    for (int ni = 0; ni < arr.size(); ++ni) {
        int n = subset.size();
        for (int sj = 0; sj < n; ++sj) {
            vector<int> set(subset[sj]);
            set.emplace_back(arr[ni]);
            subset.emplace_back(set);
        }

        while (ni + 1 < arr.size() && arr[ni] == arr[ni + 1]) {
            vector<int> set(subset.back());
            set.emplace_back(arr[++ni]);
            subset.emplace_back(set);
        }
    }

    return subset;
}

vector<vector<int>> distinctSubset2(const vector<int> &arr) {
    vector<vector<int>> subset;
    sort(subset.begin(), subset.end());

    subset.emplace_back();
    for (int ai = 0; ai < arr.size(); ++ai) {
        int sIdx = (ai > 0 && arr[ai] != arr[ai - 1]) ? 0 : subset.size() - 1;
        int eIdx = subset.size() - 1;

        for (int sj = sIdx; sj <= eIdx; ++sj) {
            vector<int> set(subset[sj]);
            set.emplace_back(arr[ai]);
            subset.emplace_back(set);
        }
    }

    return subset;
}

/*
 * Given a set of numbers that might contain duplicates, find all of its distinct subset.
 */
int main() {
    cout << distinctSubset({1, 2, 3, 3}) << endl;
    cout << distinctSubset2({1, 2, 3, 3}) << endl;
}
