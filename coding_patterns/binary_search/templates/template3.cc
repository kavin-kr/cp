#include <bits/stdc++.h>

using namespace std;

int bSearch(const vector<int> &arr, int key) {
    if (arr.empty())
        return -1;

    int left = 0, right = arr.size() - 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= key)
            left = mid;
        else
            right = mid;
    }

    if (arr[left] == key)
        return left;
    return -1;
}

/*
 * https://leetcode.com/explore/learn/card/binary-search/135/template-iii/936/
 */
int main() {
    cout << bSearch({1, 4, 6, 8, 12, 23, 56, 86}, 56) << endl;
}
