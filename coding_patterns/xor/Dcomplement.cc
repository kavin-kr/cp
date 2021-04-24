#include <bits/stdc++.h>

using namespace std;

int complement(const int num) {
    int bitCount = 0;
    for (int n = num; n > 0; n >>= 1)
        ++bitCount;

    int allBitsSet = pow(2, bitCount) - 1;

    return num ^ allBitsSet;
}

/*
 * Every non-negative integer N has a binary representation,
 * for example, 8 can be represented as “1000” in binary and 7 as “0111” in binary.
 * The complement of a binary representation is the number in binary that we get
 * when we change every 1 to a 0 and every 0 to a 1. For example, the binary complement of “1010” is “0101”.
 * For a given positive number N in base-10, return the complement of its binary representation as a base-10 integer
 */
int main() {
    cout << complement(8) << endl;
}
