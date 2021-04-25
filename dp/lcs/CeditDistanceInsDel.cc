#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
    out << "[";
    for (int i = 0, size = arr.size(); i < size; ++i)
        out << setw(2) << arr[i] << (i + 1 == size ? "" : ", ");
    out << "]";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<vector<T>> &mat) {
    out << "[";
    for (int i = 0, size = mat.size(); i < size; ++i)
        out << mat[i] << (i + 1 == size ? "" : ", \n ");
    out << "]";
    return out;
}

template<typename A, typename B>
ostream &operator<<(ostream &out, const pair<A, B> &p) {
    out << "[" << p.first << ", " << p.second << "]";
    return out;
}

struct BruteForce {
    static int solve(const string &s1, const string &s2) {
        const int n1 = s1.size(), n2 = s2.size();

        function<int(int, int)> helper = [&](int i1, int i2) {
            if (i2 == n2)
                return n1 - i1;
            if (i1 == n1)
                return n2 - i2;

            if (s1[i1] == s2[i2])
                return helper(i1 + 1, i2 + 1);

            return 1 + min(helper(i1 + 1, i2), helper(i1, i2 + 1));
        };

        return helper(0, 0);
    }
};

struct Tabulation {
    static int solve(const string &s1, const string &s2) {
        const auto n1 = s1.size(), n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= n2; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // cout << dp << endl;

        return dp[n1][n2];
    }
};

struct BruteForce2 {
    static pair<int, int> solve(const string &s1, const string &s2) {
        const auto n1 = s1.size(), n2 = s2.size();

        function<int(int, int)> helper = [&](int i1, int i2) {
            if (i1 == n1 || i2 == n2)
                return 0;

            if (s1[i1] == s2[i2])
                return 1 + helper(i1 + 1, i2 + 1);

            return max(helper(i1 + 1, i2), helper(i1, i2 + 1));
        };

        int lcs = helper(0, 0);

        auto del = s1.size() - lcs;
        auto ins = s2.size() - lcs;

        return {del, ins};
    }
};

/*
 * https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/
 */
int32_t main() {
    string s1 = "geeks";
    string s2 = "geeksforgeeks";

    cout << "BruteForce: \n" << BruteForce::solve(s1, s2) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(s1, s2) << endl;

    cout << "BruteForce2: \n" << BruteForce2::solve(s1, s2) << endl;
}
