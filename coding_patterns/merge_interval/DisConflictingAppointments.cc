#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start, stop;

    Interval(int start, int stop) : start(start), stop(stop) {}
};

bool isConflictingAppointments(vector<Interval> &arr) {
    sort(arr.begin(), arr.end(), [](const Interval &x, const Interval &y) {
        return x.start < y.start;
    });

    for (int i = 1; i < arr.size(); ++i)
        if (arr[i].start < arr[i - 1].stop)
            return true;

    return false;
}

/*
 * Given an array of intervals representing ‘N’ appointments,
 * find out if a person can attend all the appointments
 */
int main() {
    vector<Interval> arr = {{1, 4},
                            {2, 5},
                            {7, 9}};

    cout << boolalpha << isConflictingAppointments(arr) << "\n";
}