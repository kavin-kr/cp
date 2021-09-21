#include <bits/stdc++.h>

using namespace std;

constexpr int kN = 1024;
int grid[kN][kN], to_up[kN][kN], to_down[kN][kN], to_left[kN][kN], to_right[kN][kN];

void testCase() {
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }

    for (int i = 0; i <= r + 1; ++i)
        for (int j = 0; j <= c + 1; ++j) {
            to_up[i][j] = to_down[i][j] = to_left[i][j] = to_right[i][j] = 0;
        }

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (grid[i - 1][j - 1]) {
                to_up[i][j] = to_up[i - 1][j] + 1;
                to_left[i][j] = to_left[i][j - 1] + 1;
            }

    for (int i = r; i >= 1; --i)
        for (int j = c; j >= 1; --j)
            if (grid[i - 1][j - 1]) {
                to_down[i][j] = to_down[i + 1][j] + 1;
                to_right[i][j] = to_right[i][j + 1] + 1;
            }

    long long ans = 0;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            ans += max(0, min(to_up[i][j] / 2, to_left[i][j]) - 1);
            ans += max(0, min(to_up[i][j], to_left[i][j] / 2) - 1);
            ans += max(0, min(to_up[i][j] / 2, to_right[i][j]) - 1);
            ans += max(0, min(to_up[i][j], to_right[i][j] / 2) - 1);
            ans += max(0, min(to_down[i][j] / 2, to_left[i][j]) - 1);
            ans += max(0, min(to_down[i][j], to_left[i][j] / 2) - 1);
            ans += max(0, min(to_down[i][j] / 2, to_right[i][j]) - 1);
            ans += max(0, min(to_down[i][j], to_right[i][j] / 2) - 1);
        }
    cout << ans;
}

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068c509
int32_t main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        testCase();
        cout << endl;
    }
}
