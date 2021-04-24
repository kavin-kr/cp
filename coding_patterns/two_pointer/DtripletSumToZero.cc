#include <bits/stdc++.h>

using namespace std;

using triplet = tuple<int, int, int>;

vector<triplet> tripletSumToZero(vector<int> arr);

/*
 * Given an array of unsorted numbers,
 * find all unique triplets in it that add up to zero.
 */
int main() {
    for (auto &x: tripletSumToZero({-3, 0, 1, 2, -1, 1, -2, 1, 1}))
        cout << get<0>(x) << ", " << get<1>(x) << ", " << get<2>(x) << endl;
}

vector<triplet> tripletSumToZero(vector<int> arr) {
    vector<triplet> result;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 2; ++i) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int l = i + 1, r = (int) arr.size() - 1; l < r;) {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum == 0) {
                result.emplace_back(triplet{arr[i], arr[l], arr[r]});
                ++l, --r;

                while (l < r && arr[l] == arr[l - 1])
                    ++l;
                while (l < r && arr[r] == arr[r + 1])
                    --r;
            } else if (sum > 0) {
                --r;
            } else {
                ++l;
            }
        }
    }

    return result;
}
