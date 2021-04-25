#include <bits/stdc++.h>

using namespace std;

struct BruteForce {
    static int helper(int n) {
        if (n <= 1)
            return n;

        return helper(n - 1) + helper(n - 2);
    }

    static int solve(int n) {
        return helper(n);
    }
};

struct Tabulation {
    static int solve(int n) {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

struct Tabulation2 {
    static int solve(int n) {
        if (n <= 1)
            return n;

        int tmp, f0 = 0, f1 = 1;
        for (int i = 2; i <= n; ++i) {
            tmp = f0 + f1;
            f0 = f1;
            f1 = tmp;
        }

        return f1;
    }
};

/*
 * https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
 */
int32_t main() {
    int n = 9;

    cout << "BruteForce: " << endl << BruteForce::solve(n) << "\n\n";
    cout << "Tabulation: " << endl << Tabulation::solve(n) << "\n\n";
    cout << "Tabulation2: " << endl << Tabulation2::solve(n) << "\n\n";
}
