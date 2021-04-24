#include <bits/stdc++.h>

using namespace std;

pair<int, int> findPair(vector<int> &arr, int target);

/*
 * Given an array of sorted numbers and a target sum,
 * find a pair in the array whose sum is equal to the given target
 */
int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    int target = 6;

    pair<int, int> tPair = findPair(arr, target);
    cout << tPair.first << " " << tPair.second << endl;
}

pair<int, int> findPair(vector<int> &arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int curSum = arr[l] + arr[r];
        if (curSum == target) return {arr[l], arr[r]};

        if (curSum > target) --r;
        else ++l;
    }
    return {-1, -1};
}
