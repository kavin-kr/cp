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
        function<int(int, int)> helper = [&](int curr, int prev) {
            if (curr >= arr.size())
                return 0;

            int res = helper(curr + 1, prev);
            if (prev == -1 || arr[curr] > arr[prev])
                res = max(res, arr[curr] + helper(curr + 1, curr));

            return res;
        };

        return helper(0, -1);
    }
};

struct Tabulation {
    static int solve(const vector<int> &arr) {
        vector<int> dp(arr);

        for (int curr = 1; curr < arr.size(); ++curr)
            for (int prev = curr - 1; prev >= 0; --prev)
                if (arr[prev] < arr[curr]) {
                    dp[curr] = max(dp[curr], dp[prev] + arr[curr]);
                }

        int maxIdx = max_element(dp.cbegin(), dp.cend()) - dp.cbegin();
        if (maxIdx >= arr.size())
            return 0;

        vector<int> res = {arr[maxIdx]};
        for (int i = maxIdx; arr[i] != dp[i];)
            for (int j = i - 1; j >= 0; --j)
                if (dp[i] == dp[j] + arr[i]) {
                    res.push_back(arr[j]);
                    i = j;
                    break;
                }
        reverse(res.begin(), res.end());
        print(res);

        return dp[maxIdx];
    }
};

// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
int32_t main() {
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};

    cout << "BruteForce: \n" << BruteForce::solve(arr) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(arr) << endl;
}
