#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start, stop;

    Interval(int start, int stop) : start(start), stop(stop) {}
};

vector<Interval> intervalsIntersection(const vector<Interval> &arr1, const vector<Interval> &arr2) {
    vector<Interval> result;

    for (int i = 0, j = 0; i < arr1.size() && j < arr2.size();) {
        if ((arr1[i].start <= arr2[j].stop && arr1[i].stop >= arr2[j].start)
                || (arr2[j].start <= arr1[i].stop && arr2[j].stop >= arr1[i].start))
            result.emplace_back(max(arr1[i].start, arr2[j].start), min(arr1[i].stop, arr2[j].stop));

        if (arr1[i].stop < arr2[j].stop)
            ++i;
        else
            ++j;
    }

    return result;
}

/*
 * Given two lists of intervals, find the intersection of these two lists.
 * Each list consists of disjoint intervals sorted on their start time
 */
int main() {
    vector<Interval> arr1 = {{1, 3},
                             {5, 6},
                             {7, 9}};
    vector<Interval> arr2 = {{2, 3},
                             {5, 7}};
    for (Interval &x: intervalsIntersection(arr1, arr2))
        cout << x.start << " " << x.stop << "\n";
}