#include <bits/stdc++.h>
// #include "prettyprint.hpp"

using namespace std;

struct BruteForce {
    static int helper(int idx, const vector<int> &cost) {
        if (idx >= cost.size())
            return 0;

        return max(helper(idx + 1, cost), cost[idx] + helper(idx + 2, cost));
    }

    static int solve(const vector<int> &cost) {
        return helper(0, cost);
    }
};

struct Tabulation {
    static int solve(const vector<int> &cost) {
        auto n = cost.size();

        if (n == 0) return 0;
        if (n == 1) return cost[0];

        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = max(dp[0], dp[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], cost[i] + dp[i - 2]);
        }

        // cout << dp << endl;

        return dp[n - 1];
    }
};

struct Tabulation2 {
    static int solve(const vector<int> &cost) {
        auto n = cost.size();

        vector<int> dp(n + 2);
        vector<bool> used(n);
        dp[0] = dp[1] = 0;

        for (int i = 2; i < n + 2; ++i) {
            if (cost[i - 2] + dp[i - 2] > dp[i - 1]) {
                dp[i] = cost[i - 2] + dp[i - 2];
                used[i - 2] = true;
            } else {
                dp[i] = dp[i - 1];
                used[i - 2] = false;
            }
        }

        // cout << dp << endl;

        vector<int> res;
        for (int i = n-1; i >= 0; --i) {
            if (used[i]) {
                res.push_back(cost[i]);
                --i;
            }
        }

        // cout << res << endl;

        return dp[n + 1];
    }
};

/*
 * https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/
 */
int32_t main() {
    vector<int> house = {6, 7, 1, 3, 8, 2, 4};

    cout << "BruteForce: " << endl << BruteForce::solve(house) << "\n\n";
    cout << "Tabulation: " << endl << Tabulation::solve(house) << "\n\n";
    cout << "Tabulation2: " << endl << Tabulation2::solve(house) << "\n\n";
}
