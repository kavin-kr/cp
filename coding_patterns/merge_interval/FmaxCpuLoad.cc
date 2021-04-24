#include <bits/stdc++.h>

using namespace std;

struct Job {
    int start, stop, load;

    Job(int start, int stop, int load) : start(start), stop(stop), load(load) {}
};

int maxCpuLoad(vector<Job> &arr) {
    sort(arr.begin(), arr.end(), [](const Job &x, const Job &y) {
        return x.start < y.start;
    });

    struct GreaterStopComparator {
        bool operator()(const Job &x, const Job &y) {
            return x.stop > y.stop;
        }
    };
    priority_queue<Job, vector<Job>, GreaterStopComparator> minStopHeap;

    int currLoad = 0, maxLoad = 0;
    for (Job &x: arr) {
        while (!minStopHeap.empty() && minStopHeap.top().stop <= x.start) {
            currLoad -= minStopHeap.top().load;
            minStopHeap.pop();
        }

        minStopHeap.emplace(x);
        currLoad += x.load;

        maxLoad = max(maxLoad, currLoad);
    }

    return maxLoad;
}

/*
 * We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running.
 * Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine
 */
int main() {
    vector<Job> arr = {{1, 4, 3},
                       {2, 5, 4},
                       {7, 9, 6}};

    cout << maxCpuLoad(arr) << endl;
}
