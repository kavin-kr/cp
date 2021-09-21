#include <bits/stdc++.h>

using namespace std;

struct BruteForce {
    static bool solve(const string &x, const string &y, const string &z) {
        function<int(int, int, int)> helper = [&](int i, int j, int k) {
            if (i == x.size() && j == y.size() && k == z.size())
                return true;

            if (k == z.size())
                return false;

            return (x[i] == z[k] && helper(i + 1, j, k + 1)) || (y[j] == z[k] && helper(i, j + 1, k + 1));
        };

        return helper(0, 0, 0);
    }
};

struct Tabulation {
    static bool solve(const string &x, const string &y, const string &z) {
        int xl = x.size(), yl = y.size(), zl = z.size();
        if (xl + yl != zl)
            return false;

        bool dp[xl + 1][yl + 1];
        for (int i = 0; i <= xl; ++i)
            for (int j = 0; j <= yl; ++j) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (j == 0)
                    dp[i][j] = x[i - 1] == z[i + j - 1] && dp[i - 1][j];
                else if (i == 0)
                    dp[i][j] = y[j - 1] == z[i + j - 1] && dp[i][j - 1];
                else
                    dp[i][j] = (x[i - 1] == z[i + j - 1] && dp[i - 1][j])
                               || (y[j - 1] == z[i + j - 1] && dp[i][j - 1]);
            }

        for (int i = 0; i <= xl; ++i) {
            for (int j = 0; j <= yl; ++j)
                cout << dp[i][j] << " ";
            cout << endl;
        }

        return dp[xl][yl];
    }
};

// https://dev.to/seanpgallivan/solution-interleaving-string-1497#c-code
struct Tabulation2 {
    static bool solve(const string &x, const string &y, const string &z) {
        int xl = x.size(), yl = y.size(), zl = z.size();
        if (xl + yl != zl)
            return false;

        bool dp[yl + 1];
        for (int i = 0; i <= xl; ++i)
            for (int j = 0; j <= yl; ++j) {
                if (i == 0 && j == 0)
                    dp[j] = true;
                else if (j == 0)
                    dp[j] = x[i - 1] == z[i + j - 1] && dp[j];
                else if (i == 0)
                    dp[j] = y[j - 1] == z[i + j - 1] && dp[j - 1];
                else
                    dp[j] = (x[i - 1] == z[i + j - 1] && dp[j])
                            || (y[j - 1] == z[i + j - 1] && dp[j - 1]);
            }

        for (int j = 0; j <= yl; ++j)
            cout << dp[j] << " ";
        cout << endl;

        return dp[yl];
    }
};

// https://www.geeksforgeeks.org/find-if-a-string-is-interleaved-of-two-other-strings-dp-33/
int32_t main() {
    const string x = "XXY", y = "XXZ", z = "XXXXZA";

    cout << "BruteForce: \n" << BruteForce::solve(x, y, z) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(x, y, z) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(x, y, z) << endl;
}
