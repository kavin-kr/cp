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
    static int solve(const string &str) {
        function<int(int, int)> longestCommonSubSeq = [&](int i, int j) {
            if (i >= str.size() || j >= str.size())
                return 0;

            if (i != j && str[i] == str[j])
                return 1 + longestCommonSubSeq(i + 1, j + 1);

            return max(longestCommonSubSeq(i, j + 1), longestCommonSubSeq(i + 1, j));
        };

        return longestCommonSubSeq(0, 0);
    }
};

struct Tabulation {
    static int solve(const string &str) {
        const auto sz = str.size();
        vector<vector<int>> dp(sz + 1, vector<int>(sz + 1));

        for (int i = 1; i <= sz; ++i)
            for (int j = 1; j <= sz; ++j)
                if (i != j && str[i - 1] == str[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

        print(dp);

        return dp[sz][sz];
    }
};

struct Tabulation2 {
    static int solve(const string &str) {
        const auto sz = str.size();
        vector<vector<int>> dp(2, vector<int>(sz + 1));

        for (int i = 1, idx; i <= sz; ++i) {
            idx = 1 & i;
            for (int j = 1; j <= sz; ++j)
                if (i != j && str[i - 1] == str[j - 1]) {
                    dp[idx][j] = 1 + dp[1 - idx][j - 1];
                } else {
                    dp[idx][j] = max(dp[1 - idx][j], dp[idx][j - 1]);
                }
        }

        print(dp);

        return dp[1 & sz][sz];
    }
};

struct Tabulation3 {
    static int solve(const string &str) {
        const auto sz = str.size();
        vector<vector<int>> dp(sz + 1, vector<int>(sz + 1));

        for (int i = 1; i <= sz; ++i)
            for (int j = 1; j <= sz; ++j)
                if (i != j && str[i - 1] == str[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

        print(dp);

        string res;
        for (int i = sz, j = sz; i > 0 && j > 0;) {
            if (i != j && dp[i][j] == 1 + dp[i - 1][j - 1])
                res.push_back(str[--i, --j]);
            else if (dp[i][j] == dp[i - 1][j])
                --i;
            else
                --j;
        }

        std::reverse(res.begin(), res.end());
        cout << res << endl;

        return dp[sz][sz];
    }
};

// https://www.geeksforgeeks.org/longest-repeating-subsequence/
int32_t main() {
    string str = "aaabbb";

    cout << "BruteForce: \n" << BruteForce::solve(str) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(str) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(str) << endl;
    cout << "Tabulation3: \n" << Tabulation3::solve(str) << endl;
}
