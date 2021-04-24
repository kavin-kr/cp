#include <bits/stdc++.h>

using namespace std;

pair<int, int> corruptedPair(vector<int> &arr) {
    for (int i = 0; i < arr.size();)
        if (arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            ++i;

    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] != i + 1)
            return {arr[i], i + 1};

    return {-1, -1};
}

/*
 * We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’.
 * The array originally contained all the numbers from 1 to ‘n’, but due to a data error,
 * one of the numbers got duplicated which also resulted in one number going missing.
 * Find both these numbers
 */
int main() {
    vector<int> arr = {3, 1, 2, 3, 6, 4};
    pair<int, int> corrupted = corruptedPair(arr);
    cout << corrupted.first << " " << corrupted.second << "\n";
}
