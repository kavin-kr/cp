#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};

void testCase() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    priority_queue<tuple<int, int, int>> maxHeap;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
            maxHeap.emplace(grid[i][j], i, j);
        }

    long long ans = 0;

    while (!maxHeap.empty()) {
        auto topItem = maxHeap.top();
        maxHeap.pop();
        int h = get<0>(topItem), x = get<1>(topItem), y = get<2>(topItem);

        if (grid[x][y] != h)
            continue;

        for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k];
            int yy = y + dy[k];

            if (xx < 0 || xx >= r || yy < 0 || yy >= c)
                continue;

            int dh = h - 1 - grid[xx][yy];
            if (dh > 0) {
                ans += dh;
                grid[xx][yy] += dh;
                maxHeap.emplace(grid[xx][yy], xx, yy);
            }
        }
    }

    cout << ans;
}

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cb14
int32_t main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        testCase();
        cout << endl;
    }
}
