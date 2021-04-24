#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
    out << "[";
    for (int i = 0, size = arr.size(); i < size; ++i)
        out << setw(2) << arr[i] << (i + 1 == size ? "" : ", ");
    out << "]";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<vector<T>> &mat) {
    out << "[";
    for (int i = 0, size = mat.size(); i < size; ++i)
        out << mat[i] << (i + 1 == size ? "" : ", \n ");
    out << "]";
    return out;
}

struct BruteForce {
    static int helper(const int idx, const int remSum, const vector<int> &arr) {
        if (remSum == 0)
            return 1;

        if (idx >= arr.size())
            return 0;

        int count = helper(idx + 1, remSum, arr);
        if (remSum >= arr[idx])
            count += helper(idx + 1, remSum - arr[idx], arr);

        return count;
    }

    static int solve(const vector<int> &arr, const int k) {
        return helper(0, k, arr);
    }
};

struct Tabulation {
    static int solve(const vector<int> &arr, const int k) {
        if (k <= 0)
            return 0;

        vector<vector<int>> dp(arr.size() + 1, vector<int>(k + 1));
        for (int i = 0; i <= arr.size(); ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= arr[i - 1])
                        dp[i][j] += dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        cout << dp << endl;

        return dp[arr.size()][k];
    }
};

struct Tabulation2 {
    static int solve(const vector<int> &arr, const int k) {
        if (k <= 0)
            return 0;

        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for (const auto num: arr) {
            for (int j = k; j > 0; --j) {
                if (j >= num)
                    dp[j] += dp[j - num];
            }
        }

        cout << dp << endl;

        return dp[k];
    }
};

/*
 * https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/
 */
int main() {
//    vector<int> arr = {1, 1, 2, 3};
//    int k = 4;

    vector<int> arr = {1, 2, 7, 1, 5};
    int k = 9;

    cout << "BruteForce:" << endl << BruteForce::solve(arr, k) << endl << string(20, '-') << endl;
    cout << "Tabulation:" << endl << Tabulation::solve(arr, k) << endl << string(20, '-') << endl;
    cout << "Tabulation2:" << endl << Tabulation2::solve(arr, k) << endl << string(20, '-') << endl;
}
