#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &arr) {
    out << "[";
    for (int i = 0, size = arr.size(); i < size; ++i)
        out << arr[i] << (i + 1 == size ? "" : ", ");
    out << "]";
    return out;
}

vector<int> topologicalSort(const int vertices, const vector<pair<int, int>> &edges) {
    if (vertices <= 0)
        return {};

    // 1. Initialize graph
    unordered_map<int, int> inDegree;
    unordered_map<int, vector<int>> adjList;
    for (int i = 0; i < vertices; ++i) {
        inDegree[i] = 0;
        adjList[i] = {};
    }

    // 2. Build the graph
    for (auto &edge: edges) {
        inDegree[edge.second]++;
        adjList[edge.first].push_back(edge.second);
    }

    // 3. Find all sources ie inDegree = 0
    queue<int> sources;
    for (auto &v: inDegree) {
        if (v.second == 0)
            sources.emplace(v.first);
    }

    // 4. BFS to find all other secondary sources
    vector<int> sortedOrder;
    while (!sources.empty()) {
        int v = sources.front();
        sources.pop();

        sortedOrder.emplace_back(v);

        auto children = adjList[v];
        for (auto &x: children) {
            if (--inDegree[x] == 0)
                sources.emplace(x);
        }
    }

    if (sortedOrder.size() == vertices)
        return sortedOrder;
    return {};
}

/*
 * Topological Sort of a directed graph (a graph with unidirectional edges) is a linear ordering
 * of its vertices such that for every directed edge (U, V)
 * from vertex U to vertex V, U comes before V in the ordering.
 * Given a directed graph, find the topological ordering of its vertices
 */
int main() {
    cout << topologicalSort(4, {{3, 2},
                                {3, 0},
                                {2, 0},
                                {2, 1}}) << endl;
    cout << topologicalSort(5, {{4, 2},
                                {4, 3},
                                {2, 0},
                                {2, 1},
                                {3, 1}}) << endl;
    cout << topologicalSort(7, {{6, 4},
                                {6, 2},
                                {5, 3},
                                {5, 4},
                                {3, 0},
                                {3, 1},
                                {3, 2},
                                {4, 1}}) << endl;
}
