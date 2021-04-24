#include <bits/stdc++.h>

using namespace std;

int findLastPosition(const vector<int> &arr, const int key) {
    int start = 0, end = arr.size();
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= key)
            start = mid + 1;
        else
            end = mid;
    }

    if (start - 1 >= 0 && arr[start - 1] == key)
        return start - 1;

    return -1;
}

/*
 * https://mrleonhuang.gitbooks.io/lintcode/content/binary-search/last-position-of-target.html
 */
int main() {
    cout << findLastPosition({1, 2, 2, 4, 5, 5}, 6) << endl;
}
