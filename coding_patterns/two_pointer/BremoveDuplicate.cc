#include <bits/stdc++.h>

using namespace std;

int removeDuplicate(vector<int> arr);

/*
 * Given an array of sorted numbers, remove all duplicates from it.
 * You should not use any extra space
 * after removing the duplicates in-place return the new length of the array.
 */
int main() {
    cout << removeDuplicate({2, 2, 9, 11}) << endl;
}

int removeDuplicate(vector<int> arr) {
    if (arr.empty()) return 0;

    int nonDupIdx = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[nonDupIdx] != arr[i]) {
            arr[++nonDupIdx] = arr[i];
        }
    }

    return nonDupIdx + 1;
}
