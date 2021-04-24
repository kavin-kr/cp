#include <bits/stdc++.h>

using namespace std;

vector<double> avg_sub_array_of_size_k(vector<double> arr, int k);

/*
 * Given an array, find the average of all contiguous subarrays of size ‘K’ in it
 */
int main() {
    vector<double> arr = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int k = 5;

    vector<double> result = avg_sub_array_of_size_k(arr, k);
    for (auto x: result) cout << x << " ";
    cout << endl;
}

vector<double> avg_sub_array_of_size_k(vector<double> arr, int k) {
    if (k <= 0 || k > arr.size()) return {};

    vector<double> result(arr.size() - k + 1);
    double window_sum = 0;

    for (int window_start = 0, window_end = 0; window_end < arr.size(); ++window_end) {
        window_sum += arr[window_end];

        if (window_end >= k - 1) {
            result[window_start] = window_sum / k;
            window_sum -= arr[window_start++];
        }
    }

    return result;
}
