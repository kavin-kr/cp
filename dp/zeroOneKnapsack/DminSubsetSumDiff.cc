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
    static int helper(const int idx, const int sum1, const int sum2, const vector<int> &arr) {
        if (idx >= arr.size())
            return abs(sum1 - sum2);

        int diff1 = helper(idx + 1, sum1 + arr[idx], sum2, arr);
        int diff2 = helper(idx + 1, sum1, sum2 + arr[idx], arr);

        return min(diff1, diff2);
    }

    static int solve(const vector<int> &arr) {
        return helper(0, 0, 0, arr);
    }
};

struct Memoization {
    static int
    helper(const int idx, const int sum1, const int sum2, vector<vector<int>> &memo, const vector<int> &arr) {
        if (idx >= arr.size())
            return abs(sum1 - sum2);

        if (memo[idx][sum1] != -1)
            return memo[idx][sum1];

        int diff1 = helper(idx + 1, sum1 + arr[idx], sum2, memo, arr);
        int diff2 = helper(idx + 1, sum1, sum2 + arr[idx], memo, arr);

        return memo[idx][sum1] = min(diff1, diff2);
    }

    static int solve(const vector<int> &arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> memo(arr.size(), vector<int>(sum + 1, -1));
        int res = helper(0, 0, 0, memo, arr);
        cout << memo << endl;
        return res;
    }
};

struct Tabulation {
    static int solve(const vector<int> &arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int halfSum = sum / 2;

        vector<vector<bool>> dp(arr.size() + 1, vector<bool>(halfSum + 1));
        for (int i = 0; i <= arr.size(); ++i) {
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

        int ri = arr.size(), rj = halfSum;
        while (rj > 0 && !dp[ri][rj])
            --rj;

        cout << dp << endl;

        vector<int> a, b;
        for (int i = ri, j = rj; i > 0; --i) {
            if (dp[i][j] == dp[i - 1][j]) {
                a.emplace_back(arr[i - 1]);
            } else {
                b.emplace_back(arr[i - 1]);
                j -= arr[i - 1];
            }
        }
        cout << a << endl << b << endl;

        int sum1 = rj;
        int sum2 = sum - sum1;

        return abs(sum1 - sum2);
    }
};

struct Tabulation2 {
    static int solve(const vector<int> &arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int halfSum = sum / 2;

        vector<bool> dp(halfSum + 1, false);
        dp[0] = true;

        for (int i : arr)
            for (int j = halfSum; j > 0; --j)
                if (j >= i)
                    dp[j] = dp[j] | dp[j - i];

        int rj = halfSum;
        while (rj > 0 && !dp[rj])
            --rj;

        int sum1 = rj;
        int sum2 = sum - sum1;

        cout << dp << endl;

        return abs(sum1 - sum2);
    }
};

/*
 * https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
 */
int main() {
    vector<int> arr = {1, 2, 3, 9};
//    vector<int> arr = {1, 2, 7, 1, 5};
//    vector<int> arr = {1, 3, 100, 4};
//    vector<int> arr = {9, 3, 1, 2, 3, 1};

    cout << "BruteForce:" << endl << BruteForce::solve(arr) << endl << string(20, '-') << endl;
    cout << "Memoization:" << endl << Memoization::solve(arr) << endl << string(20, '-') << endl;
    cout << "Tabulation:" << endl << Tabulation::solve(arr) << endl << string(20, '-') << endl;
    cout << "Tabulation2:" << endl << Tabulation2::solve(arr) << endl << string(20, '-') << endl;
}
