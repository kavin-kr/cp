#include <bits/stdc++.h>

using namespace std;

vector<int> firstKMissingPositives(vector<int> &arr, int k) {
    for (int i = 0; i < arr.size();)
        if (arr[i] > 0 && arr[i] <= arr.size() && arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            ++i;

    vector<int> result;
    unordered_set<int> extras;
    for (int i = 0; i < arr.size() && result.size() < k; ++i)
        if (arr[i] != i + 1) {
            result.emplace_back(i + 1);
            extras.insert(arr[i]);
        }

    for (int i = (int) arr.size() + 1; result.size() < k; ++i)
        if (extras.find(i) == extras.end())
            result.emplace_back(i);

    return result;
}

/*
 * Given an unsorted array containing numbers and a number ‘k’,
 * find the first ‘k’ missing positive numbers in the array.
 */
int main() {
    vector<int> arr = {3, -1, 4, 5, 5};
    int k = 3;

    for (int &x: firstKMissingPositives(arr, k))
        cout << x << " ";
}
