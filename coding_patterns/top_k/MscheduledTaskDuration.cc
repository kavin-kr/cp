#include <bits/stdc++.h>

using namespace std;

int scheduledTaskDuration(const vector<int> &arr, const int k) {
    if (k <= 0)
        return arr.size();

    unordered_map<char, int> freq;
    for (auto &ch: arr)
        freq[ch]++;

    using Entry = pair<char, int>;
    struct LesserFreqCompare {
        bool operator()(const Entry &x, const Entry &y) const {
            return x.second < y.second;
        }
    };
    priority_queue<Entry, vector<Entry>, LesserFreqCompare> maxHeap(freq.begin(), freq.end());

    int duration = 0;
    while (!maxHeap.empty()) {
        vector<Entry> waitingList;
        int count = 0;
        for (; count < k + 1 && !maxHeap.empty(); ++count, ++duration) {
            Entry curr = maxHeap.top();
            maxHeap.pop();
            curr.second--;
            if (curr.second > 0)
                waitingList.emplace_back(curr);
        }

        // this won't work if asked to print the order
        // as heap does not maintain order of insertion while sorting
        for (auto &tmp: waitingList)
            maxHeap.push(tmp);

        // avoid addition of extra duration if k is left in an interval set but maxHeap is completed
        if (!maxHeap.empty())
            duration += k + 1 - count;
    }

    return duration;
}

int scheduledTaskDuration2(const vector<int> &arr, const int k) {
    if (k <= 0)
        return arr.size();

    unordered_map<char, int> freq;
    for (auto &ch: arr)
        freq[ch]++;

    using HeapEntry = pair<char, int>;
    struct LesserFreqCompare {
        bool operator()(const HeapEntry &x, const HeapEntry &y) const {
            return x.second < y.second;
        }
    };
    priority_queue<HeapEntry, vector<HeapEntry>, LesserFreqCompare> maxHeap(freq.begin(), freq.end());

    struct QueueEntry {
        HeapEntry heapEntry;
        int nextTime;

        QueueEntry(HeapEntry heapEntry, int nextTime) : heapEntry(std::move(heapEntry)), nextTime(nextTime) {}
    };
    queue<QueueEntry> queue;

    int duration = 0;
    while (!maxHeap.empty() || !queue.empty()) {
        if (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            if (--top.second > 0)
                queue.emplace(top, duration + k);
        }

        if (!queue.empty() && queue.front().nextTime == duration) {
            auto front = queue.front();
            queue.pop();

            maxHeap.emplace(front.heapEntry);
        }

        ++duration;
    }

    return duration;
}

// https://ericwannn.github.io/2018/06/26/leetcode-task-scheduler/
int scheduledTaskDuration3(const vector<int> &arr, const int k) {
    // follows greedy approach
    int maxFreq = 0, extTask = 0;
    unordered_map<char, int> freq;

    for (auto &ch: arr)
        maxFreq = max(maxFreq, ++freq[ch]);

    for (auto &p: freq) {
        if (p.second == maxFreq)
            ++extTask;
    }

    // Two cases:
    //  1. If unique count is greater than the ideal time between repeating tasks 
    //     then time will be equal to arr.size()
    //  2. If there are more repeating tasks then there will be ideal intervals
    //     then time will be equal to extTask + (maxFreq - 1) * (k + 1)
    return max((int) arr.size(), extTask + (maxFreq - 1) * (k + 1));
}

/*
 * You are given a list of tasks that need to be run, in any order, on a server.
 * Each task will take one CPU interval to execute but once a task has finished,
 * it has a cooling period during which it can’t be run again.
 * If the cooling period for all tasks is ‘K’ intervals, find the minimum number
 * of CPU intervals that the server needs to finish all tasks.
 * If at any time the server can’t execute any task then it must stay idle
 */
int main() {
    // k is the cooling period after a similar task in completed
    // if k is 1 then in a set 2 exclusive task have to execute
    // if k is 2 then in a set 3 exclusive task have to execute
    cout << scheduledTaskDuration2({'a', 'a', 'a', 'b', 'c', 'c'}, 2) << endl;
    cout << scheduledTaskDuration2({'a', 'b', 'a'}, 3) << endl;
}
