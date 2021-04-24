#include <bits/stdc++.h>

using namespace std;

int findClosest(const vector<int> &arr, const int key) {
    if (arr.empty())
        return -1;

    int start = 0, end = arr.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= key)
            start = mid;
        else
            end = mid;
    }

    int left = abs(arr[start] - key);
    int right = abs(arr[end] - key);
    if (left <= right)
        return start;
    return end;
}

/*
 * https://mrleonhuang.gitbooks.io/lintcode/content/binary-search/closest-number-in-sorted-array.html
 */
int main() {
    cout << findClosest({1, 1, 1, 1}, 2) << endl;
}
