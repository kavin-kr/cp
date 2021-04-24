#include <bits/stdc++.h>

using namespace std;

int findMissing(const vector<int> &arr) {
    if (arr.empty())
        return 1;

    int x1 = 1;
    for (int i = 2; i <= arr.size() + 1; ++i)
        x1 ^= i;

    int x2 = arr[0];
    for (int i = 1; i < arr.size(); ++i)
        x2 ^= arr[i];

    return x1 ^ x2;
}
    
/*
 * Given an array of n-1 integers in the range from 1 to n,
 * find the one number that is missing from the array.
 */
int main() {
    cout << findMissing({1, 5, 2, 6, 4}) << endl;
}
