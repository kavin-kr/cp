#include <bits/stdc++.h>

using namespace std;

pair<int, int> findSingleTwos(const vector<int> &arr) {
    int n1n2 = 0;
    for (auto &x: arr)
        n1n2 ^= x;

    int rightMostSetBit = 1;
    while ((rightMostSetBit & n1n2) == 0)
        rightMostSetBit <<= 1;

    int n1 = 0, n2 = 0;
    for (auto &x: arr)
        if (x & rightMostSetBit)
            n1 ^= x;
        else
            n2 ^= x;

    return {n1, n2};
}

/*
 * In a non-empty array of numbers, every number appears exactly twice
 * except two numbers that appear only once.
 * Find the two numbers that appear only once
 */
int main() {
    auto res = findSingleTwos({2, 1, 3, 2});
    cout << res.first << " " << res.second << endl;
}
