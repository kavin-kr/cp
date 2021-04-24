#include <bits/stdc++.h>

using namespace std;

string rearrangeKDistanceApart(const string &str, const int k) {
    if (k <= 1)
        return str;

    unordered_map<char, int> freq;
    for (auto &ch: str)
        freq[ch]++;

    using Entry = pair<char, int>;
    struct LesserFreqCompare {
        bool operator()(const Entry &x, const Entry &y) const {
            return x.second < y.second;
        }
    };
    priority_queue<Entry, vector<Entry>, LesserFreqCompare> maxHeap(freq.begin(), freq.end());

    string result;

    queue<Entry> queue;
    while (!maxHeap.empty()) {
        Entry curr = maxHeap.top();
        maxHeap.pop();

        result.push_back(curr.first);
        --curr.second;
        queue.push(curr);

        // for the next round if eligible add it to heap
        if (queue.size() == k) {
            Entry front = queue.front();
            queue.pop();

            if (front.second > 0)
                maxHeap.push(front);
        }
    }

    return result.size() == str.size() ? result : "-";
}

/*
 * Given a string and a number ‘K’,
 * find if the string can be rearranged such that
 * the same characters are at least ‘K’ distance apart from each other
 */
int main() {
    cout << rearrangeKDistanceApart("mmpp", 2) << endl;
    cout << rearrangeKDistanceApart("Programming", 3) << endl;
    cout << rearrangeKDistanceApart("aab", 2) << endl;
    cout << rearrangeKDistanceApart("aappa", 3) << endl;
}
