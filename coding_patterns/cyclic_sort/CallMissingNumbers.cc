#include <bits/stdc++.h>

using namespace std;

vector<int> allMissingNumbers(vector<int> &arr) {
    for (int i = 0; i < arr.size();)
        if (arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            ++i;

    vector<int> result;
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] != i + 1)
            result.emplace_back(i + 1);

    return result;
}

/*
 * We are given an unsorted array containing numbers taken from the range 1 to ‘n’.
 * The array can have duplicates, which means some numbers will be missing. Find all those missing numbers
 */
int main() {
    vector<int> arr = {2, 3, 1, 8, 2, 3, 5, 1};

    for (int &x: allMissingNumbers(arr))
        cout << x << " ";
}
