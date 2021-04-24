#include <bits/stdc++.h>

using namespace std;

string freqSort(const string &str) {
    unordered_map<char, int> freq;
    for (auto &x: str)
        freq[x]++;

    using HeapEntry = pair<char, int>;
    struct LesserFreqCompare {
        bool operator()(const HeapEntry &x, const HeapEntry &y) {
            return x.second < y.second;
        }
    };
    priority_queue<HeapEntry, vector<HeapEntry>, LesserFreqCompare> maxHeap(freq.begin(), freq.end());

    string result;
    while (!maxHeap.empty()) {
        HeapEntry tmp = maxHeap.top();
        maxHeap.pop();

        result.append(string(tmp.second, tmp.first));
    }

    return result;
}

/*
 * Given a string, sort it based on the decreasing frequency of its characters.
 */
int main() {
    cout << freqSort("Programming") << endl;
    cout << freqSort("abcbab") << endl;
}
