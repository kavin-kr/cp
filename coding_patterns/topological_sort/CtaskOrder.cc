#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &arr) {
    out << "[";
    for (int i = 0, size = arr.size(); i < size; ++i)
        out << arr[i] << (i + 1 == size ? "" : ", ");
    out << "]";
    return out;
}

vector<int> taskOrder(const int vertices, const vector<pair<int, int>> &edges) {
    if (vertices <= 0)
        return {};

    unordered_map<int, int> inDegree;
    unordered_map<int, vector<int>> adjList;
    for (int i = 0; i < vertices; ++i) {
        inDegree[i] = 0;
        adjList[i] = {};
    }

    for (auto &edge: edges) {
        inDegree[edge.second]++;
        adjList[edge.first].emplace_back(edge.second);
    }

    queue<int> sources;
    for (auto &v: inDegree) {
        if (v.second == 0)
            sources.emplace(v.first);
    }

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
 * There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite tasks
 * which need to be completed before it can be scheduled.vGiven the number of tasks and a list of
 * prerequisite pairs, write a method to find the ordering of tasks we should pick to finish all tasks.
 */
int main() {
    cout << taskOrder(3, {{0, 1},
                          {1, 2}}) << endl;
    cout << taskOrder(3, {{0, 1},
                          {1, 2},
                          {2, 0}}) << endl;
    cout << taskOrder(6, {{2, 5},
                          {0, 5},
                          {0, 4},
                          {1, 4},
                          {3, 2},
                          {1, 3}}) << endl;
}
