#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &arr) {
    for(int i=0; i<arr.size(); )
        if(arr[i] != i+1) {
            if(arr[i] != arr[arr[i]-1])
                swap(arr[i], arr[arr[i]-1]);
            else
                return arr[i];
        } else {
            ++i;
        }

    return -1;
}

/*
 * We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’.
 * The array has only one duplicate but it can be repeated multiple times.
 * Find that duplicate number without using any extra space.
 * You are, however, allowed to modify the input array.
 */
int main() {
    vector<int> arr = {2, 1, 3, 3, 5, 4};
    cout << findDuplicate(arr) << endl;
}
