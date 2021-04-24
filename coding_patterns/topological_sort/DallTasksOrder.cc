#include <bits/stdc++.h>

using namespace std;

void backTrackTopSort(vector<int> &sortedOrder,
                      unordered_map<int, int> &inDegree,
                      const vector<int> &sources,
                      const unordered_map<int, vector<int>> &adjList) {
    for (int parent: sources) {
        sortedOrder.emplace_back(parent);

        auto newSource = sources;
        newSource.erase(find(newSource.begin(), newSource.end(), parent));

        vector<int> children = adjList.at(parent);
        for (auto &child: children) {
            if (--inDegree[child] == 0)
                newSource.emplace_back(child);
        }

        backTrackTopSort(sortedOrder, inDegree, newSource, adjList);

        for (auto &child: children)
            ++inDegree[child];

        sortedOrder.erase(find(sortedOrder.begin(), sortedOrder.end(), parent));
    }

    if (sortedOrder.size() == inDegree.size()) {
        cout << "    [";
        for (int i = 0, size = sortedOrder.size(); i < size; ++i)
            cout << sortedOrder[i] << (i + 1 == size ? "" : ", ");
        cout << "]\n";
    }
}

void allTasksOrder(const int &vertices, const vector<pair<int, int>> &edges) {
    if (vertices <= 0)
        return;

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

    vector<int> sources;
    for (auto &x: inDegree) {
        if (x.second == 0)
            sources.emplace_back(x.first);
    }

    cout << "[\n";
    vector<int> sortedOrder;
    backTrackTopSort(sortedOrder, inDegree, sources, adjList);
    cout << "]" << endl << endl;
}

/*
 * There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite
 * tasks which need to be completed before it can be scheduled. Given the number of tasks
 * and a list of prerequisite pairs, write a method to print all possible
 * ordering of tasks meeting all prerequisites.
 */
int main() {
    allTasksOrder(3, {{0, 1},
                      {1, 2}});
    allTasksOrder(3, {{0, 1},
                      {1, 2},
                      {2, 0}});
    allTasksOrder(6, {{2, 5},
                      {0, 5},
                      {0, 4},
                      {1, 4},
                      {3, 2},
                      {1, 3}});
}
