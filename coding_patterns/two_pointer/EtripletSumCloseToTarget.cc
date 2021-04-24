#include <bits/stdc++.h>

using namespace std;

int tripletSumCloseToTarget(vector<int> arr, int target);

/*
 * Given an array of unsorted numbers and a target number,
 * find a triplet in the array whose sum is as close to the target number as possible,
 * return the sum of the triplet.
 * If there are more than one such triplet,
 * return the sum of the triplet with the smallest sum
 */
int main() {
    cout << tripletSumCloseToTarget({-3, -1, 1, 2}, 1) << endl;
}

int tripletSumCloseToTarget(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());

    int smallestDiff = numeric_limits<int>::max();
    for (int i = 0; i < arr.size() - 2; ++i) {
        for (int l = i + 1, r = (int) arr.size() - 1; l < r;) {
            int sum = arr[i] + arr[l] + arr[r];

            if (sum == target)
                return sum;

            if (abs(target - smallestDiff) > abs(target - sum))
                smallestDiff = sum;

            if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
    }
    return smallestDiff;
}
