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

vector<vector<int>> subsets(const vector<int> &arr) {
    vector<vector<int>> subset;

    subset.emplace_back();
    for (auto &num: arr) {
        int n = subset.size();
        for (int i = 0; i < n; ++i) {
            vector<int> set(subset[i]);
            set.emplace_back(num);
            subset.emplace_back(set);
        }
    }

    return subset;
}

/*
 * Given a set with distinct elements, find all of its distinct subsets.
 */
int main() {
    cout << subsets({1, 2, 3}) << endl;
}
