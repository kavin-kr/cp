#include <bits/stdc++.h>
using namespace std;

class DSU {
    int n, *parent;
public:
    explicit DSU(int n) : n{n} {
        parent = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    // return false if already linked otherwise return true
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
            return true;
        }
        return false;
    }

    ~DSU() {
        delete[] parent;
    }
};

void testCase() {
    int n, _;
    cin >> n;

    for (int i = 0; i < n * n; ++i)
        cin >> _;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> _;
            if (_ > 0)
                edges.emplace_back(_, i, j);
        }

    for (int i = 0; i < 2 * n; ++i)
        cin >> _;

    std::sort(edges.begin(), edges.end(), greater<>());

    long long ans = 0;
    DSU dsu = DSU(2 * n);
    for (auto[cost, i, j]: edges)
        if (!dsu.unite(i, j + n))
            ans += cost;

    cout << ans;
}

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068c2c3
int32_t main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        testCase();
        cout << endl;
    }
}
