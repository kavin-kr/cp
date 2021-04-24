#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start, stop;

    Interval(int start, int stop) : start(start), stop(stop) {}
};

// instead of creating a new list and sorting that
// since given each employee interval is sorted, use heap to utilize that
vector<Interval> findFreeTime(vector<vector<Interval>> &arr) {
    // inside vector's empty case not handled
    // for an employee his schedules should be mutually exclusive
    vector<Interval> result;

    if (arr.empty())
        return result;

    struct HeapEntry {
        int empId, index;
        Interval interval;

        HeapEntry(int empId, int index, Interval interval)
                : empId(empId), index(index), interval(interval) {}

        // custom greater start comparator for heap
        bool operator>(const HeapEntry &x) const {
            return interval.start > x.interval.start;
        }
    };
    priority_queue<HeapEntry, vector<HeapEntry>, greater<HeapEntry>> minStartHeap;

    for (int i = 0; i < arr.size(); ++i)
        minStartHeap.emplace(i, 0, arr[i][0]);

    auto prevInterval = minStartHeap.top().interval;
    while (!minStartHeap.empty()) {
        auto currEntry = minStartHeap.top();
        minStartHeap.pop();

        if (prevInterval.stop < currEntry.interval.start) {
            result.emplace_back(prevInterval.stop, currEntry.interval.start);
            prevInterval = currEntry.interval;
        } else {
            if (prevInterval.stop < currEntry.interval.stop)
                prevInterval = currEntry.interval;
        }

        if (currEntry.index + 1 < arr[currEntry.empId].size())
            minStartHeap.emplace(currEntry.empId, currEntry.index + 1, arr[currEntry.empId][currEntry.index + 1]);
    }

    return result;
}

/*
 * For ‘K’ employees, we are given a list of intervals representing the working hours of each employee.
 * Our goal is to find out if there is a free interval that is common to all employees.
 * You can assume that each list of employee working hours is sorted on the start time
 */
int main() {
    vector<vector<Interval>> arr = {{{1, 3}, {5, 6}},
                                    {{2, 3}, {6, 8}}};

    for (Interval &x: findFreeTime(arr))
        cout << x.start << " " << x.stop << endl;
}

// Simple solution can be to put the working hours of all employees in a list and sort them on the start time.
// Then we can iterate through the list to find the gaps after merging the overlapping intervals in that list.