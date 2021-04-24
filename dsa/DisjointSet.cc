#include <bits/stdc++.h>

using namespace std;

// Disjoint Set Union or Union Find
class DisjointSet {
    int n, *parent, *size;

public:
    explicit DisjointSet(int n) : n{n} {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findSet(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = findSet(parent[x]);
    }

    void unionSets(int x, int y) {
        x = findSet(x);
        y = findSet(y);

        if (x != y) {
            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }

    ~DisjointSet() {
        delete[] parent;
        delete[] size;
    }
};

int main() {
    DisjointSet dsu = DisjointSet(5);

    cout << dsu.findSet(2) << endl;

    dsu.unionSets(4, 3);
    dsu.unionSets(4, 2);

    cout << dsu.findSet(2) << endl;
}
