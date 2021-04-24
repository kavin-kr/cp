#include <bits/stdc++.h>

using namespace std;

int bSearch(vector<int> arr, int key) {
    for (int start = 0, end = arr.size() - 1; start <= end;) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

/*
 * https://leetcode.com/explore/learn/card/binary-search/125/template-i/938/
 */
int main() {
    cout << bSearch({1, 4, 6, 8, 12, 23, 56, 86}, 53) << endl;
}
