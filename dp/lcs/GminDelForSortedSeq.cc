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
        function<int(int, int)> longestIncreasingSequence = [&](int curr, int prev) {
            if (curr >= arr.size())
                return 0;

            int ans = longestIncreasingSequence(curr + 1, prev);
            if (prev == -1 || arr[curr] > arr[prev])
                ans = max(ans, 1 + longestIncreasingSequence(curr + 1, curr));

            return ans;
        };

        return arr.size() - longestIncreasingSequence(0, -1);
    }
};

struct Tabulation {
    static int solve(const vector<int> &arr) {
        vector<int> dp(arr.size(), 1);

        for (int curr = 1; curr < arr.size(); ++curr)
            for (int prev = curr - 1; prev >= 0; --prev)
                if (arr[curr] > arr[prev]) {
                    dp[curr] = max(dp[curr], 1 + dp[prev]);
                }

        const int maxIdx = max_element(dp.begin(), dp.end()) - dp.begin();
        if (maxIdx >= dp.size())
            return 0;

        vector<int> ans(arr.rbegin(), arr.rend() - maxIdx - 1);
        for (int curr = maxIdx; dp[curr] != 1;)
            for (int prev = curr - 1; prev >= 0; --prev)
                if (dp[curr] == dp[prev] + 1 && arr[curr] > arr[prev]) {
                    curr = prev;
                    break;
                } else {
                    ans.push_back(arr[prev]);
                }

        std::reverse(ans.begin(), ans.end());
        print(ans);

        return arr.size() - dp[maxIdx];
    }
};

// https://www.geeksforgeeks.org/minimum-number-deletions-make-sorted-sequence/
int32_t main() {
    vector<int> arr = {-4, 10, 3, 7, 15, 1, 23, 32, 4, 5, 8, 9, 10, 36, 3, 6};

    cout << "BruteForce: \n" << BruteForce::solve(arr) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(arr) << endl;
}
