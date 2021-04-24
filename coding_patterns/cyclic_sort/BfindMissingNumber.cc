#include <bits/stdc++.h>

using namespace std;

int findMissingNumber(vector<int> &arr) {
    for (int i = 0; i < arr.size();) {
        int j = arr[i];
        if (j < arr.size() && j != i)
            swap(arr[i], arr[j]);
        else
            ++i;
    }

    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] != i)
            return i;

    return arr.size();
}

/*
 * We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’.
 * Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.
 */
int main() {
    vector<int> arr = {8, 3, 5, 2, 4, 6, 0, 1};

    cout << findMissingNumber(arr) << endl;
}
