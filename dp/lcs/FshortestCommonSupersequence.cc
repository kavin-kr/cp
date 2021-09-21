#include <bits/stdc++.h>

using namespace std;

template<
        template<typename...> class C,
        typename... Args
>
void print(C<Args...> container) {
    cout << "[\n";
    for (const auto &innerContainer: container) {
        cout << "  [";
        for (auto it = innerContainer.cbegin(); it != innerContainer.cend();)
            cout << *it << (++it != innerContainer.cend() ? ", " : "");
        cout << "]\n";
    }
    cout << "]\n";
}

struct BruteForce {
    static int solve(const string &a, const string &b) {
        function<int(int, int)> helper = [&](int i, int j) {
            if (i >= a.size())
                return (int) b.size() - j;

            if (j >= b.size())
                return (int) a.size() - i;

            if (a[i] == b[j])
                return 1 + helper(i + 1, j + 1);

            return 1 + min(helper(i + 1, j), helper(i, j + 1));
        };

        return helper(0, 0);
    }
};

struct Tabulation {
    static int solve(const string &a, const string &b) {
        const auto x = a.size(), y = b.size();

        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        for (int i = 1; i <= x; ++i)
            dp[i][0] = i;

        for (int j = 1; j <= y; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= x; ++i)
            for (int j = 1; j <= y; ++j)
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }

        return dp[x][y];
    }

    /**
     * ALTERNATE:
     * 
     * int common = length_of_longest_common_subsequence(string a, string b)
     * int extra1 = a.size() - common
     * int extra2 = b.size() - common
     * int ans = common + extra1 + extra2
     */
};

struct Tabulation2 {
    static int solve(const string &a, const string &b) {
        int x = a.size(), y = b.size();

        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        for (int i = 1; i <= x; ++i)
            dp[i][0] = i;

        for (int j = 1; j <= y; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= x; ++i)
            for (int j = 1; j <= y; ++j)
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }

        print(dp);

        string res;
        for (int i = x, j = y; i || j;) {
            if (j > 0 && dp[i][j] == 1 + dp[i][j - 1])
                res.push_back(b[--j]);
            else if (i > 0 && dp[i][j] == 1 + dp[i - 1][j])
                res.push_back(a[--i]);
            else if (i > 0 && j > 0 && dp[i][j] == 1 + dp[i - 1][j - 1])
                res.push_back(a[--i, --j]);
        }

        reverse(res.begin(), res.end());
        cout << res << endl;

        return dp[x][y];
    }
};

// https://www.geeksforgeeks.org/shortest-common-supersequence/
int32_t main() {
    string a = "AGGTARB", b = "GXTXAYB";

    cout << "BruteForce: \n" << BruteForce::solve(a, b) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(a, b) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(a, b) << endl;
}
