#include <bits/stdc++.h>

using namespace std;

string rearrangeString(const string &str) {
    unordered_map<char, int> freq;
    for (auto &ch: str)
        freq[ch]++;

    using HeapEntry = pair<char, int>;
    struct LesserFreqCompare {
        bool operator()(const HeapEntry &x, const HeapEntry &y) {
            return x.second < y.second;
        }
    };
    priority_queue<HeapEntry, vector<HeapEntry>, LesserFreqCompare> maxHeap(freq.begin(), freq.end());

    string result;
    HeapEntry prev = {'-', -1};
    while (!maxHeap.empty()) {
        HeapEntry curr = maxHeap.top();
        maxHeap.pop();

        result.push_back(curr.first);
        --curr.second;

        if (prev.second > 0)
            maxHeap.push(prev);

        prev = curr;
    }

    return result.size() == str.size() ? result : "-";
}

/*
 * Given a string, find if its letters can be rearranged in such a way that no two same characters come next to each other
 */
int main() {
    cout << rearrangeString("aappp") << endl;
    cout << rearrangeString("Programming") << endl;
    cout << rearrangeString("aapa") << endl;
}
