#include <bits/stdc++.h>

using namespace std;

struct BruteForce {
    static int solve(const string &s1, const string &s2) {
        const auto n1 = s1.size(), n2 = s2.size();

        function<int(int, int)> helper = [&](int i, int j) {
            if (i >= n1 || j >= n2)
                return 0;

            if (s1[i] == s2[j])
                return 1 + helper(i + 1, j + 1);

            return max(helper(i + 1, j), helper(i, j + 1));
        };

        return helper(0, 0);
    }
};

struct Tabulation {
    static int solve(const string &s1, const string &s2) {
        const auto n1 = s1.size(), n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n1][n2];
    }
};

struct Tabulation2 {
    static int solve(const string &s1, const string &s2) {
        const auto n1 = s1.size(), n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string ans;
        for (auto i = n1, j = n2; i > 0 && j > 0;) {
            if (s1[i - 1] == s2[j - 1]) {
                ans.push_back(s1[i - 1]);
                --i, --j;
            } else if (dp[i][j] == dp[i - 1][j]) {
                --i;
            } else {
                --j;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;

        return dp[n1][n2];
    }
};

struct Tabulation3 {
    static int solve(string s1, string s2) {
        if (s1.size() < s2.size())
            swap(s1, s2);

        const auto n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(2, vector<int>(n2 + 1, 0));

        bool idx;
        for (int i = 1; i <= n1; ++i) {
            idx = i & 1;
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[idx][j] = 1 + dp[1 - idx][j - 1];
                else
                    dp[idx][j] = max(dp[1 - idx][j], dp[idx][j - 1]);
            }
        }

        return dp[idx][n2];
    }
};

struct Tabulation4 {
    static int solve(string s1, string s2) {
        if (s1.size() < s2.size())
            swap(s1, s2);

        const auto n1 = s1.size(), n2 = s2.size();
        vector<int> dp(n2 + 1, 0);

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1, prev = dp[0]; j <= n2; ++j) {
                int backup = dp[j];

                if (s1[i - 1] == s2[j - 1])
                    dp[j] = 1 + prev;
                else
                    dp[j] = max(dp[j], dp[j - 1]);

                prev = backup;
            }
        }

        return dp[n2];
    }
};

/*
 * https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
 */
int32_t main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout << "BruteForce: \n" << BruteForce::solve(s1, s2) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(s1, s2) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(s1, s2) << endl;
    cout << "Tabulation3: \n" << Tabulation3::solve(s1, s2) << endl;
    cout << "Tabulation4: \n" << Tabulation4::solve(s1, s2) << endl;
}
