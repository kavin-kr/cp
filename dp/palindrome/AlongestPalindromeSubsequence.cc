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
        function<int(int, int)> helper = [&](int start, int end) {
            if (start > end)
                return 0;

            if (start == end)
                return 1;

            if (str[start] == str[end])
                return 2 + helper(start + 1, end - 1);

            return max(helper(start + 1, end), helper(start, end - 1));
        };

        return helper(0, str.size() - 1);
    }
};

struct Tabulation {
    static int solve(const string &str) {
        if (str.empty())
            return 0;

        int sl = str.size();
        vector<vector<int>> dp(sl, vector<int>(sl));
        for (int i = 0; i < sl; ++i)
            dp[i][i] = 1;
        for (int i = 0; i < sl - 1; ++i)
            dp[i][i + 1] = (str[i] == str[i + 1]) ? 2 : 1;

        for (int dl = 2; dl < sl; ++dl)
            for (int i = 0, j; i < sl - dl; ++i) {
                j = i + dl;
                if (str[i] == str[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }

        // print(dp);
        return dp[0][sl - 1];
    }
};

struct Tabulation2 {
    static int solve(const string &str) {
        if (str.empty())
            return 0;

        int sl = str.size();
        vector<vector<int>> dp(sl, vector<int>(sl));
        for (int i = 0; i < sl; ++i)
            dp[i][i] = 1;
        for (int i = 0; i < sl - 1; ++i)
            dp[i][i + 1] = (str[i] == str[i + 1]) ? 2 : 1;

        for (int dl = 2; dl < sl; ++dl)
            for (int i = 0, j; i < sl - dl; ++i) {
                j = i + dl;
                if (str[i] == str[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }

        print(dp);

        int resLen = dp[0][sl - 1];
        string res(resLen, '-');
        int i = 0, j = sl - 1, k = 0;
        for (; i < j - 1;)
            if (dp[i][j] == 2 + dp[i + 1][j - 1] && str[i] == str[j]) {
                res[k] = res[resLen - 1 - k] = str[i];
                ++i;
                --j;
                ++k;
            } else if (dp[i][j] == dp[i + 1][j]) {
                ++i;
            } else {
                --j;
            }

        if (resLen > 0)
            res[k] = res[resLen - 1 - k] = str[i];

        cout << res << endl;

        return resLen;
    }
};

// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
int32_t main() {
    string str = "GEEKSKFORGEEKS";

    cout << "BruteForce: \n" << BruteForce::solve(str) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(str) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(str) << endl;
}

/*
 * ALTERNATE:
 * string str = "onion";
 * string temp(str.crbegin(), str.crend());
 * int lps = lcs(str, temp);
 */