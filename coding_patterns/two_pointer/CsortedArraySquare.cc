#include <bits/stdc++.h>

using namespace std;

vector<int> sortedArraySquare(vector<int> arr);

/*
 * Given a sorted array, create a new array containing
 * squares of all the number of the input array in the sorted order.
 */
int main() {
    for (auto &x: sortedArraySquare({-3, -1, 0, 1, 2}))
        cout << x << " ";
    cout << endl;
}

vector<int> sortedArraySquare(vector<int> arr) {
    int size = arr.size();
    vector<int> resultArr(size);

    for (int l = 0, r = size - 1, idx = size - 1; l <= r;) {
        int leftSquare = arr[l] * arr[l];
        int rightSquare = arr[r] * arr[r];

        if (leftSquare > rightSquare) {
            resultArr[idx--] = leftSquare;
            ++l;
        } else {
            resultArr[idx--] = rightSquare;
            --r;
        }
    }

    return resultArr;
}
