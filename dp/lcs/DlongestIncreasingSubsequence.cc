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
        const auto n = arr.size();

        function<int(int, int)> helper = [&](int curr, int prev) {
            if (curr >= n)
                return 0;

            int ans = helper(curr + 1, prev);
            if (prev == -1 || arr[curr] > arr[prev])
                ans = max(ans, 1 + helper(curr + 1, curr));

            return ans;
        };


        return helper(0, -1);
    }
};

struct Tabulation {
    static int solve(const vector<int> &arr) {
        int res = 0;

        vector<int> dp(arr.size(), 1);

        for (int curr = 1; curr < arr.size(); ++curr)
            for (int prev = curr - 1; prev >= 0; --prev)
                if (arr[curr] > arr[prev]) {
                    dp[curr] = max(dp[curr], dp[prev] + 1);
                    res = max(res, dp[curr]);
                }

        return res;
    }
};

struct Tabulation2 {
    static int solve(const vector<int> &arr) {
        vector<int> dp(arr.size(), 1);

        for (int curr = 1; curr < arr.size(); ++curr)
            for (int prev = curr - 1; prev >= 0; --prev)
                if (arr[curr] > arr[prev]) {
                    dp[curr] = max(dp[curr], dp[prev] + 1);
                }

        int maxIdx = max_element(dp.cbegin(), dp.cend()) - dp.cbegin();
        if (maxIdx >= arr.size())
            return 0;

        vector<int> res = {arr[maxIdx]};
        for (int i = maxIdx; dp[i] != 1;)
            for (int j = i - 1; j >= 0; --j)
                if (arr[i] > arr[j] && dp[i] == dp[j] + 1) {
                    res.push_back(arr[j]);
                    i = j;
                    break;
                }

        reverse(res.begin(), res.end());
        print(res);

        return dp[maxIdx];

    }
};

// https://afteracademy.com/blog/longest-increasing-subsequence
struct BruteForce2 {
    static int solve(const vector<int> &arr) {
        function<int(int)> lisEndingAtIdx = [&](int curr) {
            if (curr == 0)
                return 1;

            int res = 1;
            for (int i = curr - 1; i >= 0; --i)
                if (arr[i] < arr[curr]) {
                    res = max(res, 1 + lisEndingAtIdx(i));
                }

            return res;
        };

        int maxSeqLen = 0;

        for (int i = 0; i < arr.size(); ++i)
            maxSeqLen = max(maxSeqLen, lisEndingAtIdx(i));

        return maxSeqLen;
    }
};

// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
int32_t main() {
    vector<int> arr = {4, 2, 3, 6, 10, 1, 12};

    cout << "BruteForce: \n" << BruteForce::solve(arr) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(arr) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(arr) << endl;
    cout << "BruteForce2: \n" << BruteForce2::solve(arr) << endl;
}
