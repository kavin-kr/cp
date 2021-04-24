#include <bits/stdc++.h>

using namespace std;

bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &seqs) {
    // initialize
    unordered_map<int, int> inDegree;
    for (auto &v: originalSeq)
        inDegree[v] = 0;

    // build graph
    unordered_map<int, vector<int>> adjList;
    for (auto &seq: seqs) {
        for (int i = 0, size = seq.size(); i < size - 1; ++i) {
            int parent = seq[i], child = seq[i + 1];
            inDegree[child]++;
            adjList[parent].emplace_back(child);
        }
    }

    // find sources
    queue<int> sources;
    for (auto &x: inDegree) {
        if (x.second == 0)
            sources.emplace(x.first);
    }

    // BFS to find next sources
    auto itr = originalSeq.begin();
    for (; sources.size() == 1 && itr != originalSeq.end() && *itr == sources.front(); ++itr) {
        int parent = sources.front();
        sources.pop();

        for (auto &child: adjList[parent]) {
            if (--inDegree[child] == 0)
                sources.emplace(child);
        }
    }

    return sources.empty() && itr == originalSeq.end();
}

/*
 * Given a sequence originalSeq and an array of sequences, write a method to find if originalSeq
 * can be uniquely reconstructed from the array of sequences. Unique reconstruction means that we need
 * to find if originalSeq is the only sequence such that all sequences in the array are subsequences of it
 */
int main() {
    cout << boolalpha << canConstruct({1, 2, 3, 4}, {{1, 2},
                                                     {2, 3},
                                                     {3, 4}}) << endl;
    cout << boolalpha << canConstruct({1, 2, 3, 4}, {{1, 2},
                                                     {2, 3},
                                                     {2, 4}}) << endl;
    cout << boolalpha << canConstruct({3, 1, 4, 2, 5}, {{3, 1, 5},
                                                        {1, 4, 2, 5}}) << endl;
}
