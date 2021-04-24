#include <bits/stdc++.h>

using namespace std;

int longest_subarray_of_1s(vector<bool> arr, int k);

/*
 * Given an array containing 0s and 1s,
 * if you are allowed to replace no more than ‘k’ 0s with 1s,
 * find the length of the longest contiguous subarray having all 1s.
 */
int main() {
    vector<bool> arr = {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};
    int k = 2;

    cout << longest_subarray_of_1s(arr, k) << endl;
}

int longest_subarray_of_1s(vector<bool> arr, int k) {
    int max_len = 0, max_1s = 0;
    
    // extend the window only if possible
    // and keep its size even if has different chars
    for (int window_start = 0, window_end = 0; window_end < arr.size(); ++window_end) {
        if (arr[window_end]) ++max_1s;

        if (window_end - window_start + 1 - max_1s > k) {
            if (arr[window_start++]) --max_1s;
        }

        max_len = max(max_len, window_end - window_start + 1);
    }

    return max_len;
}
