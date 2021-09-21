#include <bits/stdc++.h>

using namespace std;

struct BruteForce {
    static int solve(const string &str, const string &seq) {
        function<int(int, int)> helper = [&](int strIdx, int seqIdx) {
            if (seqIdx == seq.size())
                return 1;
            if (strIdx == str.size())
                return 0;

            int ans = helper(strIdx + 1, seqIdx);
            if (str[strIdx] == seq[seqIdx])
                ans += helper(strIdx + 1, seqIdx + 1);

            return ans;
        };

        return helper(0, 0);
    }
};

struct Tabulation {
    static int solve(const string &str, const string &seq) {
        const auto strSize = str.size(), seqSize = seq.size();
        vector<vector<int>> dp(strSize + 1, vector<int>(seqSize + 1));

        for (int i = 0; i <= strSize; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= strSize; ++i)
            for (int j = 1; j <= seqSize; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (str[i - 1] == seq[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }

        return dp[strSize][seqSize];
    }
};

struct Tabulation2 {
    static int solve(const string &str, const string &seq) {
        const auto strSize = str.size(), seqSize = seq.size();
        vector<int> dp(seqSize + 1);
        dp[0] = 1;

        for (int i = 1; i <= strSize; ++i)
            for (int j = (int) seqSize; j > 0; --j) {
                if (str[i - 1] == seq[j - 1])
                    dp[j] += dp[j - 1];
            }

        return dp[seqSize];
    }
};

int32_t main() {
    string str = "tomorrow", pat = "tor";

    cout << "BruteForce: \n" << BruteForce::solve(str, pat) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(str, pat) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(str, pat) << endl;
}
