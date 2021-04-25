#include <bits/stdc++.h>

using namespace std;

struct BruteForce {
    static int solve(const string &s1, const string &s2) {
        const auto n1 = s1.size(), n2 = s2.size();

        function<int(int, int, int)> helper = [&](int i, int j, int count) {
            if (i >= n1 || j >= n2)
                return count;

            if (s1[i] == s2[j])
                count = helper(i + 1, j + 1, count + 1);

            count = max({count, helper(i + 1, j, 0), helper(i, j + 1, 0)});

            return count;
        };

        return helper(0, 0, 0);
    }
};

struct Tabulation {
    static int solve(const string &s1, const string &s2) {
        const auto n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        int count = 0;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    count = max(count, dp[i][j]);
                }
            }
        }

        return count;
    }
};

struct Tabulation2 {
    static int solve(const string &s1, const string &s2) {
        const auto n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        int count = 0, idx = -1;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (count < dp[i][j]) {
                        count = dp[i][j];
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            string ans;
            for (int i = idx - count; i < idx; ++i)
                ans.push_back(s1[i]);
            cout << ans << endl;
        }

        return count;
    }
};

/*
 * https://www.geeksforgeeks.org/longest-common-substring-dp-29/
 */
int32_t main() {
    string s1 = "passport";
    string s2 = "passept";

    cout << "BruteForce: \n" << BruteForce::solve(s1, s2) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(s1, s2) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(s1, s2) << endl;
}
