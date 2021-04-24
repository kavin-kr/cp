#include <bits/stdc++.h>

using namespace std;

int findSingleNumber(const vector<int> &arr) {
    int ans = 0;
    for(const auto &x: arr)
        ans ^= x;
    return ans;
}

/*
 * In a non-empty array of integers, every number appears twice except for one, find that single number
 */
int main() {
    cout << findSingleNumber({1, 4, 2, 1, 3, 2, 3}) << endl;
}
