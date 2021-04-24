#include <bits/stdc++.h>

using namespace std;

using triplet = tuple<int, int, int>;

vector<triplet> tripletWithSmallerSum(vector<int> arr, int target);

int tripletWithSmallerSumCount(vector<int> arr, int target);

/*
 * Given an array arr of unsorted numbers and a target sum,
 * count all triplets in it such that arr[i] + arr[j] + arr[k] < target
 * where i, j, and k are three different indices.
 * Write a function to return the count of such triplets
 */
int main() {
    vector<int> arr = {-1, 4, 2, 1, 3};
    int target = 5;

    for (auto &x: tripletWithSmallerSum(arr, target))
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;

    cout << tripletWithSmallerSumCount(arr, target) << endl;
}

vector<triplet> tripletWithSmallerSum(vector<int> arr, int target) {
    vector<triplet> result;

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 2; ++i) {
        for (int l = i + 1, r = (int) arr.size() - 1; l < r;) {
            if (arr[i] + arr[l] + arr[r] < target) {
                for (int j = l + 1; j <= r; ++j)
                    result.emplace_back(triplet{arr[i], arr[l], arr[j]});
                ++l;
            } else {
                --r;
            }
        }
    }

    return result;
}

int tripletWithSmallerSumCount(vector<int> arr, int target) {
    int count = 0;

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 2; ++i) {
        int innerCount = 0;
        for (int l = i + 1, r = (int) arr.size() - 1; l < r;) {
            if (arr[i] + arr[l] + arr[r] < target) {
                innerCount += r - l;
                ++l;
            } else {
                --r;
            }
        }
        count += innerCount;
    }

    return count;
}
