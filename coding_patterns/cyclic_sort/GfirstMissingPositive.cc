#include <bits/stdc++.h>

using namespace std;

int firstMissingPositive(vector<int> &arr) {
    for (int i = 0; i < arr.size();)
        if (arr[i] > 0 && arr[i] <= arr.size() && arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            ++i;

    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] != i + 1)
            return i + 1;

    return (int) arr.size() + 1;
}

/*
 * Given an unsorted array containing numbers, find the smallest missing positive number in it.
 */
int main() {
    vector<int> arr = {3, -2, 0, 1, 2};
    cout << firstMissingPositive(arr) << endl;
}