#include <bits/stdc++.h>
using namespace std;

struct BruteForce {
    static int g(int n) {
        if (n <= 1)
            return n;
        return f(n - 1) + g(n - 1);
    }

    static int f(int n) {
        if (n <= 2)
            return n;
        return f(n - 1) + f(n - 2) + (2 * g(n - 2));
    }

    static int solve(int n) {
        return f(n);
    }
};

struct Tabulation {
    static constexpr int MOD = 1E9 + 7;

    // Solution is based on https://www.youtube.com/watch?v=CecjOo4Zo-g
    static int solve(int n) {
        vector<vector<int>> dp(4, vector<int>(n + 1, 0));
        dp[3][0] = 1;
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[3][j - 1];
            dp[1][j] = (dp[2][j - 1] + dp[0][j - 1]) % MOD;
            dp[2][j] = (dp[1][j - 1] + dp[0][j - 1]) % MOD;
            dp[3][j] = (((dp[3][j - 1] + dp[0][j - 1]) % MOD) + ((dp[2][j - 1] + dp[1][j - 1]) % MOD)) % MOD;
        }
        return dp[3][n];
    }
};

/*
 * https://leetcode.com/problems/domino-and-tromino-tiling
 */
int32_t main() {
    int n = 10;

    cout << "BruteForce: " << BruteForce::solve(n) << endl;
    cout << "Tabulation: " << Tabulation::solve(n) << endl;
}
