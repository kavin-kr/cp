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
    static int helper(int idx, int amount, const vector<int> &denominations) {
        if (amount == 0)
            return 0;

        if (idx >= denominations.size())
            return numeric_limits<int>::max() - 1;

        int ans = helper(idx + 1, amount, denominations);
        if (denominations[idx] <= amount)
            ans = min(ans, 1 + helper(idx, amount - denominations[idx], denominations));

        return ans;
    }

    static int solve(int amount, const vector<int> &denominations) {
        return helper(0, amount, denominations);
    }
};

struct Tabulation {
    static int solve(int amount, const vector<int> &denominations) {
        vector<vector<int>> dp(denominations.size() + 1, vector<int>(amount + 1));

        for (int i = 0; i <= denominations.size(); ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = numeric_limits<int>::max() - 1;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (denominations[i - 1] <= j)
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j - denominations[i - 1]]);
                }
            }
        }

        cout << dp << endl;

        vector<int> used;
        for (int i = denominations.size(), j = amount; i > 0; --i) {
            while (i > 0 && j > 0 && dp[i][j] != dp[i - 1][j]) {
                used.emplace_back(denominations[i - 1]);
                j -= denominations[i - 1];
            }
        }

        cout << used << endl;

        return dp[denominations.size()][amount];
    }
};

struct Tabulation2 {
    static int solve(int amount, const vector<int> &denominations) {
        vector<int> dp(amount + 1, numeric_limits<int>::max() - 1);
        dp[0] = 0;
        for (int denomination : denominations) {
            for (int j = 0; j <= amount; ++j) {
                if (denomination <= j)
                    dp[j] = min(dp[j], 1 + dp[j - denomination]);
            }
        }

        cout << dp << endl;

        return dp[amount];
    }
};

struct Tabulation3 {
    static int solve(int amount, const vector<int> &denominations) {
        vector<int> dp(amount + 1, numeric_limits<int>::max() - 1);
        vector<int> used(amount + 1, -1);

        dp[0] = 0;
        for (int i = 0; i < denominations.size(); ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (denominations[i] <= j && 1 + dp[j - denominations[i]] < dp[j]) {
                    dp[j] = 1 + dp[j - denominations[i]];
                    used[j] = i;
                }
            }
        }

        cout << dp << endl;

        vector<int> ans;
        for (int j = amount; j > 0; j -= denominations[used[j]]) {
            ans.emplace_back(denominations[used[j]]);
        }

        cout << ans << endl;

        return dp[amount];
    }
};

/*
 * https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
 */
int main() {
    int amount = 9;
    vector<int> denominations = {5, 2, 1};

    cout << "BruteForce: " << "\n" << BruteForce::solve(amount, denominations) << "\n\n";
    cout << "Tabulation: " << "\n" << Tabulation::solve(amount, denominations) << "\n\n";
    cout << "Tabulation2: " << "\n" << Tabulation2::solve(amount, denominations) << "\n\n";
    cout << "Tabulation3: " << "\n" << Tabulation3::solve(amount, denominations) << "\n\n";
}
