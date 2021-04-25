#include <bits/stdc++.h>
//#include "prettyprint.hpp"

using namespace std;

struct BruteForce {
    static double helper(int idx, const vector<int> &arr) {
        if (idx >= arr.size()) return 0;

        double ans = numeric_limits<double>::infinity();
        for (int i = 1; i <= arr[idx]; ++i)
            ans = min(ans, 1 + helper(idx + i, arr));

        return ans;
    }

    static double solve(const vector<int> &arr) {
        return helper(0, arr);
    }
};

struct Tabulation {
    static double solve(const vector<int> &arr) {
        vector<double> dp(arr.size(), numeric_limits<double>::infinity());

        dp[0] = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j <= arr[i] + i && j < arr.size(); ++j) {
                dp[j] = min(dp[j], 1 + dp[i]);
            }
        }

//        cout << dp << endl;

        return dp[arr.size() - 1];
    }
};

struct Tabulation2 {
    static double solve(const vector<int> &arr) {
        vector<double> dp(arr.size(), numeric_limits<double>::infinity());
        vector<int> used(arr.size(), -1);

        dp[0] = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j <= arr[i] + i && j < arr.size(); ++j) {
                if (1 + dp[i] < dp[j]) {
                    dp[j] = 1 + dp[i];
                    used[j] = i;
                }
            }
        }

//        cout << dp << endl;

        vector<int> ans;
        if (!isinf(dp[arr.size() - 1])) {
            for (int i = arr.size() - 1; i > 0; i = used[i])
                ans.push_back(arr[i]);
        }
        ans.push_back(arr[0]);
//        cout << ans << endl;

        return dp[arr.size() - 1];
    }
};

/*
 * https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
 */
int32_t main() {
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << "BruteForce: " << endl << BruteForce::solve(arr) << "\n\n";
    cout << "Tabulation: " << endl << Tabulation::solve(arr) << "\n\n";
    cout << "Tabulation2: " << endl << Tabulation2::solve(arr) << "\n\n";
}
