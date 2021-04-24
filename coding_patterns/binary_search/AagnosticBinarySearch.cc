#include <bits/stdc++.h>

using namespace std;

int agnosticBinarySearch(vector<int> arr, int key) {
    int start = 0, end = (int) arr.size() - 1;
    bool isAscend = arr[start] <= arr[end];
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;

        if (isAscend) {
            if (arr[mid] > key)
                end = mid - 1;
            else
                start = mid + 1;
        } else {
            if (arr[mid] > key)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}

/*
 * Given a sorted array of numbers, find if a given number ‘key’ is present in the array.
 * Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order.
 * You should assume that the array can have duplicates.
 * Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1
 */
int main() {
    cout << agnosticBinarySearch({1, 2, 3, 4, 5, 6, 7}, 5) << endl;
    cout << agnosticBinarySearch({23, 13, 9, 7, 4, -2}, -2) << endl;
}
