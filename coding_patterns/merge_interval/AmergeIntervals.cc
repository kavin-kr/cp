#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start, stop;

    Interval(int start, int stop)
            : start(start), stop(stop) {}
};

vector<Interval> mergeIntervals(vector<Interval> &arr) {
    if (arr.size() < 2)
        return arr;

    sort(arr.begin(), arr.end(), [](const Interval &x, const Interval &y) {
        return x.start < y.start;
    });

    vector<Interval> result;

    Interval tmp = arr[0];
    for (int i = 1; i < arr.size(); ++i)
        if (arr[i].start > tmp.stop) { // not overlaps
            result.push_back(tmp);
            tmp = arr[i];
        } else {
            tmp.stop = max(tmp.stop, arr[i].stop);
        }

    result.emplace_back(tmp);
    return result;
}

/*
 * Given a list of intervals, merge all the overlapping intervals 
 * to produce a list that has only mutually exclusive intervals
 */
int main() {
    vector<Interval> arr = {{1, 4},
                            {2, 5},
                            {7, 9}};

    for (Interval &x: mergeIntervals(arr))
        cout << x.start << ", " << x.stop << "\n";
}
