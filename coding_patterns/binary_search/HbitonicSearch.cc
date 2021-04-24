#include <bits/stdc++.h>

using namespace std;

int bitonicMaxIndex(const vector<int> &arr) {
    if (arr.empty())
        return -1;

    int start = 0, end = (int) arr.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= arr[mid + 1])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

int orderAgnosticSearch(const vector<int> &arr, const int key, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[start] < arr[end]) { // ascending
            if (arr[mid] > key)
                end = mid - 1;
            else
                start = mid + 1;
        } else { // descending
            if (arr[mid] > key)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int bitonicSearch(const vector<int> &arr, const int key) {
    int maxIdx = bitonicMaxIndex(arr);
    if (maxIdx == -1)
        return -1;

    // used maxIdx inclusive in both search so that
    // no index out of bound error will happen in second search
    // otherwise additional check is needed
    int res = orderAgnosticSearch(arr, key, 0, maxIdx);
    if (res == -1)
        res = orderAgnosticSearch(arr, key, maxIdx, (int) arr.size() - 1);

    return res;
}

/*
 * Given a Bitonic array, find if a given ‘key’ is present in it.
 * An array is considered bitonic if it is monotonically increasing and then monotonically decreasing.
 * Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].
 * Write a function to return the index of the ‘key’. If the ‘key’ is not present, return -1
 */
int main() {
    cout << bitonicSearch({1, 3, 8, 4, 3}, 4) << endl;
    cout << bitonicSearch({3, 8, 3, 1}, 8) << endl;
    cout << bitonicSearch({1, 3, 8, 12}, 12) << endl;
    cout << bitonicSearch({10, 9, 8}, 10) << endl;
    cout << bitonicSearch({10, 9, 8}, 110) << endl;
}
