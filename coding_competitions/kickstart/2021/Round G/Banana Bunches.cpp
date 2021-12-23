#include <bits/stdc++.h>
using namespace std;

#define int long long

void testCase() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int &i: arr)
        cin >> i;

    int ans = INT_MAX;
    vector<int> secBest(k + 1, INT_MAX);
    secBest[0] = 0;
    for (int i = n - 1; i >= 0; --i) {
        int sum = 0;
        for (int j = i; j >= 0; --j) {
            sum += arr[j];
            if (sum <= k)
                ans = min(ans, i - j + 1 + secBest[k - sum]);
            else
                break;
        }

        sum = 0;
        for (int j = i; j < n; ++j) {
            sum += arr[j];
            if (sum <= k)
                secBest[sum] = min(secBest[sum], j - i + 1);
            else
                break;
        }
    }

    if (ans == INT_MAX)
        ans = -1;

    cout << ans;
}

// https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b44ef#problem
int32_t main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        testCase();
        cout << endl;
    }
}
