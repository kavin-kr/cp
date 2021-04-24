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

class BruteForce {
    static bool helper(const int idx, const int remSum, const vector<int> &arr) {
        if (remSum == 0)
            return true;

        if (idx >= arr.size())
            return false;

        bool res = helper(idx + 1, remSum, arr);
        if (remSum >= arr[idx])
            res |= helper(idx + 1, remSum - arr[idx], arr);

        return res;
    }

public:
    static bool solve(const vector<int> &arr, const int sum) {
        return helper(0, sum, arr);
    }
};

class Tabulation {
public:
    static bool solve(const vector<int> &arr, const int sum) {
        vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1));
        for (int i = 0; i <= arr.size(); ++i) {
            for (int j = 0; j <= sum; ++j) {
                if (j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = false;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= arr[i - 1]) {
                        dp[i][j] = dp[i][j] | dp[i - 1][j - arr[i - 1]];
                    }
                }
            }
        }

        cout << dp << endl;

        if (dp[arr.size()][sum]) {
            vector<int> res;

            for (int i = arr.size(), j = sum; i > 0; --i)
                if (dp[i][j] != dp[i - 1][j]) {
                    res.emplace_back(arr[i - 1]);
                    j -= arr[i - 1];
                }

            cout << res << endl;
        }

        return dp[arr.size()][sum];
    }
};

class Tabulation2 {
public:
    static bool solve(const vector<int> &arr, const int sum) {
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (int i : arr) {
            for (int j = sum; j > 0; --j) {
                if (j >= i) {
                    dp[j] = dp[j] | dp[j - i];
                }
            }
        }

        cout << dp << endl;

        return dp[sum];
    }
};

/*
 * https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
 */
int main() {
    vector<int> arr = {1, 3, 4, 8};
//    vector<int> arr = {1, 2, 3, 7};
    int sum = 6;

    cout << boolalpha;
    cout << "BruteForce:" << endl << BruteForce::solve(arr, sum) << endl << endl;
    cout << "Tabulation:" << endl << Tabulation::solve(arr, sum) << endl << endl;
    cout << "Tabulation2:" << endl << Tabulation2::solve(arr, sum) << endl << endl;
}
