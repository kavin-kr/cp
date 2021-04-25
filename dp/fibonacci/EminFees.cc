#include <bits/stdc++.h>
//#include "prettyprint.hpp"

using namespace std;

struct BruteForce {
    static int helper(int idx, const vector<int> &cost) {
        if (idx >= cost.size())
            return 0;

        return cost[idx] + min(helper(idx + 1, cost), helper(idx + 2, cost));
    }

    static int solve(const vector<int> &cost) {
        return min(helper(0, cost), helper(1, cost));
    }
};

struct Tabulation {
    static int solve(const vector<int> &cost) {
        int n = cost.size();
        if (n <= 1) return 0;

        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // cout << dp << endl;

        return min(dp[n - 1], dp[n - 2]);
    }
};

/*
 * https://www.geeksforgeeks.org/minimum-cost-to-reach-the-top-of-the-floor-by-climbing-stairs/
 */
int32_t main() {
    vector<int> cost = {2, 5, 3, 1, 7, 3, 4};

    cout << "BruteForce: " << endl << BruteForce::solve(cost) << "\n\n";
    cout << "Tabulation: " << endl << Tabulation::solve(cost) << "\n\n";
}
