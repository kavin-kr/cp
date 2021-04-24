#include <bits/stdc++.h>

using namespace std;

int small_subarray_sum_atleast_k(vector<int> arr, int k);

/*
 * Given an array of positive numbers and a positive number ‘S’, 
 * find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. 
 * Return 0, if no such subarray exists.
 */
int main() {
    vector<int> arr = {2, 1, 5, 2, 8};
    int k = 7;

    cout << small_subarray_sum_atleast_k(arr, k) << endl;
}

int small_subarray_sum_atleast_k(vector<int> arr, int k) {
    int sum = 0, min_len = numeric_limits<int>::max();

    for (int window_start = 0, window_end = 0; window_end < arr.size(); ++window_end) {
        sum += arr[window_end];

        while (sum >= k) {
            min_len = min(min_len, window_end - window_start + 1);
            sum -= arr[window_start++];
        }
    }

    return min_len == numeric_limits<int>::max() ? 0 : min_len;
}
