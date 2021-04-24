#include <bits/stdc++.h>

using namespace std;

int rotationCount(const vector<int> &arr) {
    int start = 0, end = (int) arr.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;

        if (mid < end && arr[mid] > arr[mid + 1])
            return mid + 1;
        if (mid > start && arr[mid - 1] > arr[mid])
            return mid;

        if (arr[start] < arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return 0;
}

/*
 * Given an array of numbers which is sorted in ascending order and
 * is rotated ‘k’ times around a pivot, find ‘k’.
 * You can assume that the array does not have any duplicates
 */
int main() {
    cout << rotationCount({4, 5, 7, 9, 10, -1, 2}) << endl;
    cout << rotationCount({1, 3, 8, 10}) << endl;
}
