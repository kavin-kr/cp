#include <bits/stdc++.h>

using namespace std;

class ArrayReader {
    vector<int> arr;
public:
    explicit ArrayReader(const vector<int> &arr) : arr(arr) {}

    int get(int index) const {
        if (index >= arr.size())
            return numeric_limits<int>::max();

        return arr[index];
    }
};

int findKeyInInfiniteSorted(const ArrayReader &arrayReader, const int key) {
    // [start, end)
    int end = 1;
    while (arrayReader.get(end) < key)
        end *= 2;
    int start = end / 2;

    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arrayReader.get(mid) < key)
            start = mid + 1;
        else
            end = mid;
    }

    if (arrayReader.get(start) == key)
        return start;
    return -1;
}

/*
 * Given an infinite sorted array (or an array with unknown size), find if a given number ‘key’ is present in the array.
 * Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.
 * Since it is not possible to define an array with infinite (unknown) size,
 * you will be provided with an interface ArrayReader to read elements of the array.
 * ArrayReader.get(index) will return the number at index
 * if the array’s size is smaller than the index, it will return Integer.MAX_VALUE.
 */
int main() {
    ArrayReader arrayReader = ArrayReader({4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
    cout << findKeyInInfiniteSorted(arrayReader, 16) << endl;
    cout << findKeyInInfiniteSorted(arrayReader, 11) << endl;

    arrayReader = ArrayReader({1, 3, 8, 10, 15});
    cout << findKeyInInfiniteSorted(arrayReader, 15) << endl;
    cout << findKeyInInfiniteSorted(arrayReader, 200) << endl;
}
