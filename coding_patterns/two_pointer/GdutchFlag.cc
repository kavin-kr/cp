#include <bits/stdc++.h>

using namespace std;

vector<int> dutchFlag(vector<int> arr);

/*
 * Given an array containing 0s, 1s and 2s, sort the array in-place.
 * You should treat numbers of the array as objects,
 * hence, we can’t count 0s, 1s, and 2s to recreate the array.
 */
int main() {
    for (auto x: dutchFlag({1, 0, 2, 1, 0}))
        cout << x << " ";
}

vector<int> dutchFlag(vector<int> arr) {
    int low = 0, high = (int) arr.size() - 1;
    for (int i = 0; i < high;) {
        if (arr[i] == 0)
            swap(arr[i++], arr[low++]);
        else if (arr[i] == 1)
            ++i;
        else
            swap(arr[i], arr[high--]);
    }
    return arr;
}
