#include <bits/stdc++.h>

using namespace std;

struct BruteForce {
    static int solve(const string &s1, const string &s2) {
        function<int(int, int)> helper = [&](int i, int j) {
            if (i >= s1.size())
                return (int) s2.size() - j;

            if (j >= s2.size())
                return (int) s1.size() - i;

            if (s1[i] == s2[j])
                return helper(i + 1, j + 1);

            return 1 + min({helper(i + 1, j + 1), helper(i, j + 1), helper(i + 1, j)});
        };

        return helper(0, 0);
    }
};

struct Tabulation {
    static int solve(const string &s1, const string &s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
        for (int i = 1; i < s1.size(); ++i)
            dp[i][0] = i;
        for (int j = 1; j < s2.size(); ++j)
            dp[0][j] = j;

        for (int i = 1; i <= s1.size(); ++i)
            for (int j = 1; j <= s2.size(); ++j)
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                }

        return dp[s1.size()][s2.size()];
    }
};

struct Tabulation2 {
    static int solve(const string &s1, const string &s2) {
        vector<vector<int>> dp(2, vector<int>(s2.size() + 1));
        for (int j = 1; j < s2.size(); ++j)
            dp[0][j] = j;

        for (int i = 1, idx; i <= s1.size(); ++i) {
            idx = i & 1;
            dp[idx][0] = i;
            for (int j = 1; j <= s2.size(); ++j)
                if (s1[i - 1] == s2[j - 1]) {
                    dp[idx][j] = dp[1 - idx][j - 1];
                } else {
                    dp[idx][j] = 1 + min({dp[1 - idx][j - 1], dp[idx][j - 1], dp[1 - idx][j]});
                }
        }

        return dp[1 & s1.size()][s2.size()];
    }
};

// https://www.geeksforgeeks.org/edit-distance-dp-5/
int32_t main() {
    const string s1 = "sunday", s2 = "saturday";

    cout << "BruteForce: \n" << BruteForce::solve(s1, s2) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(s1, s2) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(s1, s2) << endl;
}

/*
 * Another approach: (If asked no of insertions and deletions only)
 * int lcsLength = lcs(s1, s2);
 * no of insertions = s2.size() - lcsLength;
 * no of deletions = s1.size() - lcsLength;
 *
 * total operations = s1.size() + s2.size() - (2 * lcsLength)
 *
 *
 * If replacement is also allowed, then this may not work
 * Ex: 3 operations
 * ABAC
 * ADEA
 */