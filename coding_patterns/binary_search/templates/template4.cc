#include <bits/stdc++.h>

using namespace std;

int bSearch(const vector<int> &arr, int key) {
    if (arr.empty())
        return -1;

    int idx = 0;
    for (int step = (int) arr.size() / 2; step >= 1; step /= 2)
        while (idx + step < arr.size() && arr[idx + step] <= key)
            idx += step;

    if (arr[idx] == key)
        return idx;

    return -1;
}

/*
 * https://codeforces.com/blog/entry/9901
 */
int main() {
    cout << bSearch({3, 5, 12, 34, 111}, 12) << endl;
}
