#include <bits/stdc++.h>

using namespace std;

struct BruteForce {
    static int solve(int n) {
        if (n <= 2) return n;

        return solve(n - 1) + solve(n - 2);
    }
};

struct Tabulation {
    static int solve(int n) {
        if (n <= 2) return n;

        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

struct Tabulation2 {
    static int solve(int n) {
        if (n <= 2) return n;

        int tmp, f1 = 1, f2 = 2;
        for (int i = 3; i <= n; ++i) {
            tmp = f1 + f2;
            f1 = f2;
            f2 = tmp;
        }

        return f2;
    }
};

/*
 * https://www.iarcs.org.in/inoi/online-study-material/topics/dp-tiling.php
 * 1st problem
 */
int32_t main() {
    int n = 4;

    cout << "BruteForce: \n" << BruteForce::solve(n) << "\n\n";
    cout << "Tabulation: \n" << Tabulation::solve(n) << "\n\n";
    cout << "Tabulation2: \n" << Tabulation2::solve(n) << "\n\n";
}
