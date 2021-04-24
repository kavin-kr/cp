#include <bits/stdc++.h>

using namespace std;

int rotationCountWithDuplicates(const vector<int> &arr) {
    int start = 0, end = (int) arr.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;

        if (mid < end && arr[mid] > arr[mid + 1])
            return mid + 1;
        if (mid > start && arr[mid - 1] > arr[mid])
            return mid;

        // when the numbers at indices start, middle, and end are the same,
        // we can’t decide which part of the array is sorted.
        // In such a case, the best we can do is to skip one number from both ends:
        // start = start + 1 & end = end - 1
        if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
            if (arr[start] > arr[start + 1])
                return start + 1;
            ++start;

            if (arr[end - 1] > arr[end])
                return end;
            --end;
        } else if (arr[start] < arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return 0;
}

/*
 * How do we find the rotation count of a sorted and rotated array that has duplicates too?
 * NOTE: the shortest element must not have duplicates
 */
int main() {
    cout << rotationCountWithDuplicates({3, 3, 3, 3, 3, 2, 2, 2}) << endl;
    cout << rotationCountWithDuplicates({3, 3, 3, 3, 3, 2, 2, 2, 3}) << endl;
}
