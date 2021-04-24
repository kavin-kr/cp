#include <bits/stdc++.h>

using namespace std;

int bSearch(const vector<int> &arr, const int key) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid;
    }

    if (left != arr.size() && arr[left] == key)
        return left;

    return -1;
}

/*
 * https://leetcode.com/explore/learn/card/binary-search/126/template-ii/937/
 */
int main() {
    cout << bSearch({1, 4, 6, 8, 12, 23, 56, 86}, 86) << endl;
}
