#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/data_structures/disjoint_set_union.html
// https://www.cs.usfca.edu/~galles/visualization/DisjointSets.html
// https://usaco.guide/gold/dsu?lang=cpp
struct DSU {
    vector<int> arr;

    // 0-based indexing
    DSU(int n) {
        arr = vector<int>(n, -1);
    }

    int get(int x) {
        if (arr[x] < 0)
            return x;
        return arr[x] = get(arr[x]);  // path compression
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return false;

        if (arr[x] > arr[y])  // union by size
            swap(x, y);
        arr[x] += arr[y];
        arr[y] = x;
        return true;
    }

    bool isSameSet(int x, int y) {
        return get(x) == get(y);
    }

    int size(int x) {
        return -arr[get(x)];
    }
};

int32_t main() {
    DSU dsu = DSU(6);

    cout << dsu.get(2) << endl;
    cout << dsu.get(1) << endl;

    cout << dsu.unite(1, 3) << endl;
    cout << dsu.unite(1, 2) << endl;
    cout << dsu.unite(1, 4) << endl;
    cout << dsu.unite(1, 4) << endl;
    cout << dsu.unite(0, 5) << endl;


    cout << dsu.size(1) << endl;
    cout << dsu.size(4) << endl;
    cout << dsu.size(0) << endl;
}