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

vector<vector<int>> permutation(const vector<int> &arr) {
    vector<vector<int>> result;

    queue<vector<int>> queue;
    queue.emplace();
    for (const int &num: arr) {
        for (int qi = 0, qSize = queue.size(); qi < qSize; ++qi) {
            vector<int> oldPerm = queue.front();
            queue.pop();

            for (int i = 0; i <= oldPerm.size(); ++i) {
                vector<int> newPerm(oldPerm);
                newPerm.insert(newPerm.begin() + i, num);

                if (newPerm.size() == arr.size())
                    result.emplace_back(newPerm);
                else
                    queue.emplace(newPerm);
            }
        }
    }

    return result;
}

class PermutationRecurse {
    static void permutationHelper(const vector<int> &arr, int idx, vector<int> &curr, vector<vector<int>> &result) {
        if (curr.size() == arr.size()) {
            result.emplace_back(curr);
        } else {
            for (int i = 0; i <= curr.size(); ++i) {
                vector<int> newPerm(curr);
                newPerm.insert(newPerm.begin() + i, arr[idx]);
                permutationHelper(arr, idx + 1, newPerm, result);
            }
        }
    }

public:
    static vector<vector<int>> permutation(const vector<int> &arr) {
        vector<vector<int>> result;

        vector<int> curr;
        permutationHelper(arr, 0, curr, result);

        return result;
    }
};

/*
 * Given a set of distinct numbers, find all of its permutations.
 */
int main() {
    cout << permutation({1, 2, 3}) << endl;

    cout << PermutationRecurse::permutation({1, 2, 3}) << endl;
}
