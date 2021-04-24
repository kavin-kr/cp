#include <bits/stdc++.h>

using namespace std;

string findDictionaryOrder(const vector<string> &words) {
    // Initialize
    unordered_map<char, int> inDegree;
    for (auto &word: words) {
        for (auto &ch: word)
            inDegree[ch] = 0;
    }

    // Build graph
    unordered_map<char, vector<char>> adjList;
    for (int i = 0; i < words.size() - 1; ++i) {
        const string &str1 = words[i], &str2 = words[i + 1];
        for (int j = 0, size = min(str1.size(), str2.size()); j < size; ++j) {
            const char &parent = str1[j], &child = str2[j];
            if (parent != child) {
                inDegree[child]++;
                adjList[parent].emplace_back(child);
                break;
            }
        }
    }

    // Find initial sources
    queue<char> sources;
    for (auto &entry: inDegree) {
        if (entry.second == 0)
            sources.emplace(entry.first);
    }

    // BFS to find all other sources
    string sortedOrder;
    while (!sources.empty()) {
        char parent = sources.front();
        sources.pop();

        sortedOrder.push_back(parent);

        for (const char &child: adjList[parent]) {
            if (--inDegree[child] == 0)
                sources.emplace(child);
        }
    }

    if (sortedOrder.size() == inDegree.size())
        return sortedOrder;
    return {};
}

/*
 * There is a dictionary containing words from an alien language
 * for which we don’t know the ordering of the characters.
 * Write a method to find the correct order of characters in the alien language
 */
int main() {
    cout << findDictionaryOrder({"ba", "bc", "ac", "cab"}) << endl;
    cout << findDictionaryOrder({"cab", "aaa", "aab"}) << endl;
    cout << findDictionaryOrder({"ywx", "wz", "xww", "xz", "zyy", "zwz"}) << endl;
}
