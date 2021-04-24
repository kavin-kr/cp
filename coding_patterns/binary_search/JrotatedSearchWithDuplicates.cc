#include <bits/stdc++.h>

using namespace std;

int rotatedSearchWithDuplicates(const vector<int> &arr, const int key) {
    for (int start = 0, end = (int) arr.size() - 1; start <= end;) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;

        // when the numbers at indices start, middle, and end are the same,
        // we can’t decide which part of the array is sorted.
        // In such a case, the best we can do is to skip one number from both ends:
        // start = start + 1 & end = end - 1
        if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
            ++start;
            --end;
        } else if (arr[start] <= arr[mid]) {   // [start, mid] is sorted
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

/*
 * How do we search in a sorted and rotated array that also has duplicates?
 */
int main() {
    cout << rotatedSearchWithDuplicates({1, 2, 10, 1, 1, 1, 1, 1, 1}, 10) << endl;
}
