#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start, stop;

    Interval(int start, int stop)
            : start(start), stop(stop) {}
};

vector<Interval> insertInterval(vector<Interval> arr, Interval newInterval) {
    if (arr.empty())
        return {newInterval};

    int i = 0;
    vector<Interval> result;

    while (i < arr.size() && arr[i].stop < newInterval.start)
        result.emplace_back(arr[i++]);

    while (i < arr.size() && arr[i].start <= newInterval.stop) {
        newInterval.start = min(newInterval.start, arr[i].start);
        newInterval.stop = max(newInterval.stop, arr[i++].stop);
    }
    result.emplace_back(newInterval);

    while (i < arr.size())
        result.emplace_back(arr[i++]);

    return result;
}

/*
 * Given a list of non-overlapping intervals sorted by their start time,
 * insert a given interval at the correct position and merge all necessary intervals
 * to produce a list that has only mutually exclusive intervals.
 */
int main() {
    vector<Interval> arr = {{1, 3},
                            {5, 7},
                            {8, 12}};
    Interval newInterval = {4, 10};

    for (Interval &x: insertInterval(arr, newInterval))
        cout << x.start << ", " << x.stop << "\n";
}
