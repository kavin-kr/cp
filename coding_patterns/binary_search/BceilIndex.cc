#include <bits/stdc++.h>

using namespace std;

int ceilIndex(const vector<int> &arr, const int key) {
    int start = 0, end = arr.size();
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid;
    }

    if (start != arr.size())
        return start;
    return -1;
}

/*
 * Given an array of numbers sorted in an ascending order, find the ceiling of a given number ‘key’.
 * The ceiling of the ‘key’ will be the smallest element in the given array greater than or equal to the ‘key’.
 * Write a function to return the index of the ceiling of the ‘key’. If there isn’t any ceiling return -1
 */
int main() {
    cout << ceilIndex({4, 6, 10}, 6) << endl;
    cout << ceilIndex({1, 3, 8, 10, 15}, 12) << endl;
    cout << ceilIndex({4, 6, 10}, 17) << endl;
    cout << ceilIndex({4, 6, 10}, -1) << endl;
}
