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
    static int solve(const vector<int> &arr, const int k) {
        return helper(0, 0, arr, k);
    }

    static int helper(const int idx, const int currDiff, const vector<int> &arr, const int k) {
        if (idx >= arr.size())
            return (currDiff == k) ? 1 : 0;

        int count = helper(idx + 1, currDiff + arr[idx], arr, k);
        count += helper(idx + 1, currDiff - arr[idx], arr, k);

        return count;
    }
};

struct BruteForce2 {
    /*
     * s1 - set of numbers with + sign
     * s2 - set of numbers with - sign
     * k  - diff between 2 sets
     *
     * sum(s1) - sum(s2) = k
     * sum(s1) + sum(s2) = sum(arr)
     *
     * 2 * sum(s1) = k + sum(arr)
     * sum(s1) = (k + sum(arr)) / 2
     */
    static int solve(const vector<int> &arr, const int k) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        return helper(0, (sum + k) / 2, arr);
    }

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
};

struct Tabulation {
    static int solve(const vector<int> &arr, const int k) {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        // if k + sum is odd, then two sets diff won't be equal to k
        if (sum < k || (k + sum) % 2 == 1)
            return 0;

        sum = (k + sum) / 2;
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1));
        for (int i = 0; i <= arr.size(); ++i) {
            for (int j = 0; j <= sum; ++j) {
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

        return dp[arr.size()][sum];
    }
};

struct Tabulation2 {
    static int solve(const vector<int> &arr, const int k) {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        // if k + sum is odd, then two sets diff won't be equal to k
        if (sum < k || (k + sum) % 2 == 1)
            return 0;

        sum = (k + sum) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (const auto i: arr)
            for (int j = sum; j > 0; --j) {
                if (j >= i)
                    dp[j] += dp[j - i];
            }

        cout << dp << endl;

        return dp[sum];
    }
};

/*
 * https://leetcode.com/problems/target-sum/solution/
 */
int main() {
//    vector<int> arr = {1, 1, 2, 3};
//    int k = 1;

    vector<int> arr = {1, 2, 7, 1};
    int k = 9;

    cout << "BruteForce:" << endl << BruteForce::solve(arr, k) << endl << string(20, '-') << endl;
    cout << "BruteForce2:" << endl << BruteForce2::solve(arr, k) << endl << string(20, '-') << endl;
    cout << "Tabulation:" << endl << Tabulation::solve(arr, k) << endl << string(20, '-') << endl;
    cout << "Tabulation2:" << endl << Tabulation2::solve(arr, k) << endl << string(20, '-') << endl;
}
