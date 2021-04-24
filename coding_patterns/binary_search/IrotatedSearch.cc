#include <bits/stdc++.h>

using namespace std;

int rotatedSearch(const vector<int> &arr, const int key) {
    for (int start = 0, end = (int) arr.size() - 1; start <= end;) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[start] <= arr[mid]) {   // [start, mid] is sorted
            if (key >= arr[start] && key < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        } else {                        // [mid+1, end] is sorted
            if (key > arr[mid] && key <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int rotatedSearch2(const vector<int> &arr, const int key) {
    if(arr.empty())
        return -1; 

    int start = 0, end = (int) arr.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[start] <= arr[mid]) {   // [start, mid] is sorted
            if (key >= arr[start] && key <= arr[mid])
                end = mid;
            else
                start = mid + 1;
        } else {                        // [mid+1, end] is sorted
            if (key >= arr[mid] && key <= arr[end])
                start = mid;
            else
                end = mid - 1;
        }
    }

    if (arr[start] == key)
        return start;

    return -1;
}

/*
 * Given an array of numbers which is sorted in ascending order
 * and also rotated by some arbitrary number, find if a given ‘key’ is present in it.
 * Write a function to return the index of the ‘key’ in the rotated array.
 * If the ‘key’ is not present, return -1.
 * --- You can assume that the given array does not have any duplicates ---
 */
int main() {
    cout << rotatedSearch2({10, 15, 1, 3, 8}, 10) << endl;
    cout << rotatedSearch2({4, 5, 7, 9, 10, -1, 2}, 2) << endl;
    cout << rotatedSearch2({4, 5, 7, 9, 10, -1, 2}, 10) << endl;
    cout << rotatedSearch2({4, 5, 7, 9, 10, -1, 2}, 101) << endl;
    cout << rotatedSearch2({3, 2}, 2) << endl;
}
