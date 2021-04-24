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
    static bool helper(int idx, int remSum, const vector<int> &arr) {
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
    static bool solve(const vector<int> &arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        // only if sum is even we can split into two subsets
        if (sum % 2 == 0)
            return helper(0, sum / 2, arr);

        return false;
    }
};

class Tabulation {
public:
    static bool solve(const vector<int> &arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if (sum % 2 != 0)
            return false;

        const int arrSize = arr.size(), halfSum = sum / 2;
        vector<vector<bool>> dp(arrSize + 1, vector<bool>(halfSum + 1));

        for (int i = 0; i <= arrSize; ++i) {
            for (int j = 0; j <= halfSum; ++j) {
                if (j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = false;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= arr[i - 1])
                        dp[i][j] = dp[i][j] | dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        cout << dp << endl;

        if (dp[arrSize][halfSum]) {
            vector<int> a, b;
            for (int i = arrSize, j = halfSum; i > 0; --i) {
                if (dp[i][j] == dp[i - 1][j]) {
                    a.emplace_back(arr[i - 1]);
                } else {
                    b.emplace_back(arr[i - 1]);
                    j -= arr[i - 1];
                }
            }

            cout << a << endl << b << endl;
        }

        return dp[arrSize][halfSum];
    }

};

class Tabulation2 {
public:
    static bool solve(const vector<int> &arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if (sum % 2 != 0)
            return false;

        const int halfSum = sum / 2;
        vector<bool> dp(halfSum + 1, false);
        dp[0] = true;

        for (const auto &num: arr) {
            for (int j = halfSum; j > 0; --j)
                if (j >= num)
                    dp[j] = dp[j] | dp[j - num];
        }

        cout << dp << endl;

        return dp[halfSum];
    }

};

/*
 * https://www.geeksforgeeks.org/partition-problem-dp-18/
 */
int main() {
//    vector<int> arr = {1, 1, 3, 4, 7};
    vector<int> arr = {2, 3, 5, 2};

    cout << boolalpha;
    cout << "BruteForce: " << endl << BruteForce::solve(arr) << endl << endl;
    cout << "Tabulation: " << endl << Tabulation::solve(arr) << endl << endl;
    cout << "Tabulation2: " << endl << Tabulation2::solve(arr) << endl << endl;
}
