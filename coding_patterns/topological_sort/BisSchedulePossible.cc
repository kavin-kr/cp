#include <bits/stdc++.h>

using namespace std;

bool isSchedulePossible(const int vertices, const vector<pair<int, int>> &edges) {
    if (vertices <= 0)
        return false;

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

    return sortedOrder.size() == vertices;
}

/*
 * There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’.
 * Each task can have some prerequisite tasks which need to be completed before it can be scheduled.
 * Given the number of tasks and a list of prerequisite pairs, find out if it is possible to schedule all the tasks
 */
int main() {
    cout << isSchedulePossible(3, {{0, 1},
                                   {1, 2}}) << endl;
    cout << isSchedulePossible(3, {{0, 1},
                                   {1, 2},
                                   {2, 0}}) << endl;
    cout << isSchedulePossible(6, {{2, 5},
                                   {0, 5},
                                   {0, 4},
                                   {1, 4},
                                   {3, 2},
                                   {1, 3}}) << endl;
}
