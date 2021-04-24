#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &arr) {
    out << "[";
    for (int size = arr.size(), i = 0; i < size; ++i)
        out << arr[i] << (i + 1 == arr.size() ? "" : ", ");
    out << "]";
    return out;
}

int binarySearchClosest(const vector<int> &arr, const int target) {
    if (arr.empty())
        return -1;

    int start = 0, end = (int) arr.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (target >= arr[mid])
            start = mid;
        else
            end = mid;
    }

    int left = abs(arr[start] - target);
    int right = abs(arr[end] - target);

    if (left <= right)
        return start;
    else
        return end;
}

vector<int> findKClosestNumbers(const vector<int> &arr, const int k, const int target) {
    int closestIdx = binarySearchClosest(arr, target);
    if (closestIdx == -1)
        return {};

    int start = closestIdx, end = closestIdx;

    while ((end - start + 1 < k) && (start > 0) && (end < arr.size() - 1)) {
        int left = abs(arr[start - 1] - target);
        int right = abs(arr[end + 1] - target);

        if (left <= right)
            --start;
        else
            ++end;
    }

    while ((end - start + 1 < k) && (start > 0))
        --start;

    while ((end - start + 1 < k) && (end < arr.size() - 1))
        ++end;

    return {arr.begin() + start, arr.begin() + end + 1};
}

/*
 * Given a sorted number array and two integers ‘K’ and ‘X’, find ‘K’ closest numbers to ‘X’ in the array.
 * Return the numbers in the sorted order. ‘X’ is not necessarily present in the array.
 */
int main() {
    cout << findKClosestNumbers({5, 6, 7, 8, 9}, 3, 7) << endl;
    cout << findKClosestNumbers({2, 4, 5, 6, 9}, 3, 6) << endl;
    cout << findKClosestNumbers({2, 4, 5, 6, 9}, 3, 10) << endl;
}
