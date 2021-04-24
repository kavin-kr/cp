#include <bits/stdc++.h>

using namespace std;

int bitonicMaxLinear(const vector<int> &arr) {
    if (arr.empty())
        throw length_error("Empty arr cannot be bitonic");

    int i = 0;
    while (i + 1 < arr.size() && arr[i] <= arr[i + 1])
        ++i;

    return arr[i];
}

int bitonicMax(const vector<int> &arr) {
    if (arr.empty())
        throw length_error("Empty arr cannot be bitonic");

    int start = 0, end = (int) arr.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= arr[mid + 1])
            start = mid + 1;
        else
            end = mid;
    }

    return arr[end];
}

/*
 * Find the maximum value in a given Bitonic array. An array is considered bitonic
 * if it is monotonically increasing and then monotonically decreasing.
 * Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1]
 */
int main() {
    cout << bitonicMax({1, 3, 8, 12, 4, 2}) << endl;
    cout << bitonicMax({3, 8, 3, 1}) << endl;
    cout << bitonicMax({1, 3, 8, 12}) << endl;
    cout << bitonicMax({10, 9, 8}) << endl;
    cout << bitonicMax({9}) << endl;

}
