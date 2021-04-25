#include <bits/stdc++.h>

using namespace std;

struct BruteForce {
    static int solve(int n) {
        if (n < 0) return 0;

        if (n <= 2) return 1;
        else if (n == 3) return 2;

        return solve(n - 1) + solve(n - 3) + solve(n - 4);
    }
};

struct Tabulation {
    static int solve(int n) {
        if (n < 0) return 0;

        if (n <= 2) return 1;
        else if (n == 3) return 2;

        int dp[n + 1];
        dp[0] = dp[1] = dp[2] = 1;
        dp[3] = 2;

        for (int i = 4; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 4];

        return dp[n];
    }
};

/*
 * https://www.geeksforgeeks.org/count-ofdifferent-ways-express-n-sum-1-3-4/
 */
int32_t main() {
    int n = 14;

    cout << "BruteForce: " << endl << BruteForce::solve(n) << "\n\n";
    cout << "Tabulation: " << endl << Tabulation::solve(n) << "\n\n";
}
