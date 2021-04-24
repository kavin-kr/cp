#include <bits/stdc++.h>

using namespace std;

int shortestWindowSort(vector<int> arr);

/*
 * Given an array, find the length of the smallest subarray in it
 * which when sorted will sort the whole array.
 */
int main() {
    cout << shortestWindowSort({1, 3, 2, 0, -1, 7, 10}) << endl;
}

int shortestWindowSort(vector<int> arr) {
    int l = 0, r = (int) arr.size() - 1;

    while (l < arr.size() - 1 && arr[l] <= arr[l + 1])
        ++l;

    if (l == r)
        return 0;

    while (r > 0 && arr[r] >= arr[r - 1])
        --r;

    int smallest = arr[l], largest = arr[l];
    for (int i = l + 1; i <= r; ++i) {
        if (smallest > arr[i])
            smallest = arr[i];
        if (largest < arr[i])
            largest = arr[i];
    }

    while (l > 0 && smallest < arr[l - 1])
        --l;
    while (r < arr.size() - 1 && largest > arr[r + 1])
        ++r;

    return r - l + 1;
}
