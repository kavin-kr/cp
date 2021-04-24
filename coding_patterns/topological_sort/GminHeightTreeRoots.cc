#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &arr) {
    out << "[";
    for (int i = 0, size = arr.size(); i < size; ++i)
        out << arr[i] << (i + 1 == size ? "" : ", ");
    out << "]";
    return out;
}

vector<int> minHeightTreeRoots(const int vertices, const vector<pair<int, int>> &edges) {
    // initialize
    unordered_map<int, int> inDegree;
    for (int i = 0; i < vertices; ++i)
        inDegree[i] = 0;

    // build adjList
    unordered_map<int, vector<int>> adjList;
    for (auto &edge: edges) {
        inDegree[edge.first]++;
        inDegree[edge.second]++;

        adjList[edge.first].emplace_back(edge.second);
        adjList[edge.second].emplace_back(edge.first);
    }

    // find initial sources
    deque<int> sources;
    for (auto &x: inDegree) {
        if (x.second == 1)
            sources.push_back(x.first);
    }

    // BFS to find next sources
    int totalNodes = vertices;
    while (totalNodes > 2 && !sources.empty()) {
        for (int i = 0, size = sources.size(); i < size; ++i, --totalNodes) {
            int leaf = sources.front();
            sources.pop_front();

            for (auto &nextLeaf: adjList[leaf]) {
                if (--inDegree[nextLeaf] == 1)
                    sources.push_back(nextLeaf);
            }
        }
    }

    if (totalNodes <= 2 && sources.size() <= 2)
        return {sources.begin(), sources.end()};
    return {};
}

/*
 * We are given an undirected graph that has characteristics of a k-ary tree. In such a graph,
 * we can choose any node as the root to make a k-ary tree. The root (or the tree) with the minimum height
 * will be called Minimum Height Tree (MHT). There can be multiple MHTs for a graph. In this problem,
 * we need to find all those roots which give us MHTs. Write a method to find all
 * MHTs of the given graph and return a list of their roots
 */
int main() {
    cout << minHeightTreeRoots(5, {{0, 1},
                                   {1, 2},
                                   {1, 3},
                                   {2, 4}}) << endl;
    cout << minHeightTreeRoots(4, {{0, 1},
                                   {0, 2},
                                   {2, 3}}) << endl;
    cout << minHeightTreeRoots(4, {{0, 1},
                                   {1, 2},
                                   {1, 3}}) << endl;
}
