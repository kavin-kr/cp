#include <bits/stdc++.h>

using namespace std;

template<
        template<typename...> class C,
        typename... Args
>
void print(C<Args...> container) {
    cout << "[";
    for (auto it = container.cbegin(); it != container.cend();)
        cout << *it << (++it != container.cend() ? ", " : "");
    cout << "]\n";
}

struct BruteForce {
    static int solve(const vector<int> &arr) {
        function<int(int)> lesserEnding, greaterEnding;

        greaterEnding = [&](int currIdx) {
            int ans = 1;
            for (int i = currIdx - 1; i >= 0; --i)
                if (arr[currIdx] > arr[i]) {
                    ans = max(ans, 1 + lesserEnding(i));
                }
            return ans;
        };

        lesserEnding = [&](int currIdx) {
            int ans = 1;
            for (int i = currIdx - 1; i >= 0; --i)
                if (arr[currIdx] < arr[i]) {
                    ans = max(ans, 1 + greaterEnding(i));
                }
            return ans;
        };

        int maxLen = 0;
        for (int i = 0; i < arr.size(); ++i)
            maxLen = max({maxLen, greaterEnding(i), lesserEnding(i)});
        return maxLen;
    }
};

struct Tabulation {
    static int solve(const vector<int> &arr) {
        int dp[2][arr.size()]; // dp[0] --> greaterEnding, dp[1] --> lesserEnding
        for (int i = 0; i < arr.size(); ++i)
            dp[0][i] = dp[1][i] = 1;

        int maxLen = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (arr[j] < arr[i])
                    dp[0][i] = max(dp[0][i], 1 + dp[1][j]);
                else
                    dp[1][i] = max(dp[1][i], 1 + dp[0][j]);
            }
            maxLen = max({maxLen, dp[0][i], dp[1][i]});
        }

        return maxLen;
    }
};

struct Tabulation2 {
    static int solve(const vector<int> &arr) {
        int dp[2][arr.size()]; // dp[0] --> greaterEnding, dp[1] --> lesserEnding
        for (int i = 0; i < arr.size(); ++i)
            dp[0][i] = dp[1][i] = 1;

        int maxIdx = 0;
        bool isLessEnd = false;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i - 1; j >= 0; --j)
                if (arr[j] < arr[i]) {
                    dp[0][i] = max(dp[0][i], 1 + dp[1][j]);
                } else {
                    dp[1][i] = max(dp[1][i], 1 + dp[0][j]);
                }

            if (maxIdx == -1 || maxIdx < max(dp[0][i], dp[1][i])) {
                maxIdx = i;
                isLessEnd = dp[0][i] < dp[1][i];
            }
        }

        if (maxIdx == -1)
            return 0;

        list<int> ans;
        ans.push_front(dp[isLessEnd][maxIdx]);
        for (int i = maxIdx; dp[isLessEnd][i] != 1; isLessEnd = !isLessEnd)
            for (int j = i - 1; j >= 0; --j)
                if (1 + dp[!isLessEnd][j] == dp[isLessEnd][i]) {
                    ans.push_front(arr[j]);
                    i = j;
                    break;
                }
        print(ans);

        return dp[isLessEnd][maxIdx];
    }
};

// https://iq.opengenus.org/longest-alternating-subsequence/
// https://www.geeksforgeeks.org/longest-alternating-subsequence/
int32_t main() {
    //    vector<int> arr = {2, 3, 4, 8, 2, 5, 6, 8}; // 4
    //    vector<int> arr = {2, 3, 4, 8, 2, 6, 5, 4}; // 5
    vector<int> arr = {6, 5, 9, 2, 10, 77, 5}; // 6

    cout << "BruteForce: \n" << BruteForce::solve(arr) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(arr) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(arr) << endl;
}

/*
// BruteForce based on prev index value
cout << max(las(0, INT_MIN, true), las(0, INT_MAX, false));

int las(int idx, int pre, bool dir)
{
    if(idx == n)
        return 0;

    int count = las(idx+1, pre, dir);

    if(dir and arr[idx] > pre)
        count = max(count, 1+las(idx+1, arr[idx], false));
    else if(!dir and arr[idx] < pre)
        count = max(count, 1+las(idx+1, arr[idx], true));

    return count;
}
*/
