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
            return 1;

        if (idx >= denominations.size())
            return 0;

        int ans = helper(idx + 1, amount, denominations);
        if (denominations[idx] <= amount)
            ans += helper(idx, amount - denominations[idx], denominations);

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
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= denominations[i - 1])
                        dp[i][j] += dp[i][j - denominations[i - 1]];
                }
            }
        }

        cout << dp << endl;

        return dp[denominations.size()][amount];
    }
};

struct Tabulation2 {
    static int solve(int amount, const vector<int> &denominations) {
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;
        for (int denomination : denominations) {
            for (int j = 1; j <= amount; ++j) {
                if (j >= denomination)
                    dp[j] += dp[j - denomination];
            }
        }

        cout << dp << endl;

        return dp[amount];
    }
};

/*
 * https://www.geeksforgeeks.org/coin-change-dp-7/
 */
int main() {
    vector<int> denominations = {1, 2, 3};
    int amount = 4;

    cout << "BruteForce: " << "\n" << BruteForce::solve(amount, denominations) << "\n\n";
    cout << "Tabulation: " << "\n" << Tabulation::solve(amount, denominations) << "\n\n";
    cout << "Tabulation2: " << "\n" << Tabulation2::solve(amount, denominations) << "\n\n";
}
