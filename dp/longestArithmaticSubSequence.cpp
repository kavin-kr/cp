// https://leetcode.com/problems/longest-arithmetic-subsequence/discuss/1511097/C%2B%2B-oror-Maps-giving-TLE-oror-Use-Vectors
// https://www.youtube.com/watch?v=Lm38EAoDc7c
int longestArithSeqLength(vector<int> &nums) {
    int n = (int) nums.size();
    if (n <= 2)
        return n;

    vector<unordered_map<int, int>> dp(n);

    int maxLength = 1;
    for (int i = 1; i < n; ++i)
        for (int j = i - 1; j >= 0; --j) {
            int d = nums[i] - nums[j];
            if (dp[i].find(d) == dp[i].end())
                dp[i][d] = 2;
            if (dp[j].find(d) != dp[j].end())
                dp[i][d] = max(dp[i][d], 1 + dp[j][d]);
            maxLength = max(maxLength, dp[i][d]);
        }

    return maxLength;
}
