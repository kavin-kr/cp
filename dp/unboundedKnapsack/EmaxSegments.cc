#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
    out << "[";
    for (int i = 0, size = arr.size(); i < size; ++i)
        out << arr[i] << (i + 1 == size ? "" : ", ");
    out << "]";
    return out;
}

struct BruteForce {
    static int helper(int idx, int n, const vector<int> &seg) {
        if (n == 0)
            return 0;

        if (idx >= seg.size())
            return numeric_limits<int>::min();

        int ans = helper(idx + 1, n, seg);
        if (seg[idx] <= n)
            ans = max(ans, 1 + helper(idx, n - seg[idx], seg));

        return ans;
    }

    static int solve(int n, const vector<int> &seg) {
        return helper(0, n, seg);
    }
};

struct Tabulation {
    static int solve(int n, const vector<int> &seg) {
        vector<vector<int>> dp(seg.size() + 1, vector<int>(n + 1));

        for (int i = 0; i <= seg.size(); ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = numeric_limits<int>::min();
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (seg[i - 1] <= j)
                        dp[i][j] = max(dp[i][j], 1 + dp[i][j - seg[i - 1]]);
                }
            }
        }

        vector<int> ans;
        for (int i = seg.size(), j = n; j > 0; --i) {
            while (dp[i][j] != dp[i - 1][j]) {
                ans.emplace_back(seg[i - 1]);
                j -= seg[i - 1];
            }
        }

        cout << ans << endl;

        return dp[seg.size()][n];
    }
};

struct Tabulation2 {
    static int solve(int n, const vector<int> &seg) {
        vector<int> dp(n + 1, numeric_limits<int>::min());
        dp[0] = 0;

        for (int i : seg) {
            for (int j = 1; j <= n; ++j) {
                if (i <= j)
                    dp[j] = max(dp[j], 1 + dp[j - i]);
            }
        }

        return dp[n];
    }
};

struct Tabulation3 {
    static int solve(int n, const vector<int> &seg) {
        vector<int> dp(n + 1, numeric_limits<int>::min());
        vector<int> used(n + 1, -1);

        dp[0] = 0;
        for (int i : seg) {
            for (int j = 1; j <= n; ++j) {
                if (i <= j && dp[j] < 1 + dp[j - i]) {
                    dp[j] = 1 + dp[j - i];
                    used[j] = i;
                }
            }
        }

        vector<int> ans;
        for (int j = n; j > 0; j -= used[j]) {
            ans.emplace_back(used[j]);
        }
        cout << ans << endl;

        return dp[n];
    }
};

/*
 * https://www.geeksforgeeks.org/maximum-number-segments-lengths-b-c/
 */
int32_t main() {
    int n = 7;
    vector<int> seg = {5, 2, 5};

    cout << "BruteForce: " << "\n" << BruteForce::solve(n, seg) << "\n\n";
    cout << "Tabulation: " << "\n" << Tabulation::solve(n, seg) << "\n\n";
    cout << "Tabulation2: " << "\n" << Tabulation2::solve(n, seg) << "\n\n";
    cout << "Tabulation3: " << "\n" << Tabulation3::solve(n, seg) << "\n\n";
}
