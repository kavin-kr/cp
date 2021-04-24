#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const pair<int, int> &pair) {
    out << "[" << pair.first << ", " << pair.second << "]";
    return out;
}

pair<int, int> findRange(const vector<int> &arr, const int key) {
    // find first index
    int start = 0, end = arr.size();
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid;
    }

    if (start == arr.size() || arr[start] != key)
        return {-1, -1};

    int first = start;

    // find last index
    end = arr.size();
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= key)
            start = mid + 1;
        else
            end = mid;
    }

    int second = start - 1;
    return {first, second};
}

/*
 * Given an array of numbers sorted in ascending order, find the range of a given number ‘key’.
 * The range of the ‘key’ will be the first and last position of the ‘key’ in the array.
 * Write a function to return the range of the ‘key’. If the ‘key’ is not present return [-1, -1]
 */
int main() {
    cout << findRange({4, 6, 6, 6, 9}, 6) << endl;
    cout << findRange({1, 3, 8, 10, 15}, 10) << endl;
    cout << findRange({1, 3, 8, 10, 15}, 12) << endl;
}
