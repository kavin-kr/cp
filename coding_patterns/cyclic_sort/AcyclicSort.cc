#include <bits/stdc++.h>

using namespace std;

void cyclicSort(vector<int> &arr) {
    for (int i = 0; i < arr.size();) {
        int j = arr[i] - 1;
        if (j != i)
            swap(arr[i], arr[j]);
        else
            ++i;
    }
}

/*
 * We are given an array containing ‘n’ objects. Each object, when created, was assigned a unique number
 * from 1 to ‘n’ based on their creation sequence. This means that the object with sequence number ‘3’
 * was created just before the object with sequence number ‘4’.
 * Write a function to sort the objects in-place on their creation sequence number in O(n) and without any extra space.
 * For simplicity, let’s assume we are passed an integer array containing only the sequence numbers,
 * though each number is actually an object
 */
int main() {
    vector<int> arr = {2, 6, 4, 3, 1, 5};

    cyclicSort(arr);
    for (auto &x: arr)
        cout << x << " ";
}
