#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start, stop;

    Interval(int start, int stop) : start(start), stop(stop) {}
};

int minMeetingRooms(vector<Interval> arr) {
    sort(arr.begin(), arr.end(), [](const Interval &x, const Interval &y) {
        return x.start < y.start;
    });

    struct GreaterStopCompare {
        bool operator() (const Interval &x, const Interval &y) {
            return x.stop > y.stop;
        }
    };
    priority_queue<Interval, vector<Interval>, GreaterStopCompare> minStopHeap;

    int minRooms = 0;
    for (Interval &x: arr) {
        while (!minStopHeap.empty() && minStopHeap.top().stop <= x.start)
            minStopHeap.pop();

        minStopHeap.emplace(x);

        minRooms = max(minRooms, (int) minStopHeap.size());
    }

    return minRooms;
}

/*
 * Given a list of intervals representing the start and end time of ‘N’ meetings,
 * find the minimum number of rooms required to hold all the meetings.
 */
int main() {
    vector<Interval> arr = {{4, 5},
                            {2, 3},
                            {2, 4},
                            {3, 5}};

    cout << minMeetingRooms(arr) << endl;
}
