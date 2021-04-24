#include <bits/stdc++.h>

using namespace std;

int max_sum_sub_array_of_size_k(vector<int> arr, int k);

/*
 * Given an array of positive numbers and a positive number ‘k’,
 * find the maximum sum of any contiguous subarray of size ‘k’
 */
int main() {
    // constrain: array should contain only positive numbers 
    vector<int> arr = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int k = 5;

    cout << max_sum_sub_array_of_size_k(arr, k) << endl;
}

int max_sum_sub_array_of_size_k(vector<int> arr, int k) {
    if (k <= 0 || k > arr.size()) return -1;

    int sum = 0, max_sum = numeric_limits<int>::min();
    for (int window_start = 0, window_end = 0; window_end < arr.size(); ++window_end) {
        sum += arr[window_end];

        if (window_end >= k - 1) {
            if (sum > max_sum) max_sum = sum;
            sum -= arr[window_start++];
        }
    }

    return max_sum;
}
