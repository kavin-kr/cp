#include <bits/stdc++.h>

using namespace std;

class KthSmallestNumber {
    static int partition(vector<int> &arr, int low, int high) {
        if (low == high)
            return low;

        // randomize pivot
        srand(time(nullptr));
        int pivotIndex = low + (rand() % (high - low));
        swap(arr[high], arr[pivotIndex]);

        int pivot = arr[high];
        for (int i = low; i < high; ++i)
            if (arr[i] < pivot) {
                swap(arr[i], arr[low++]);
            }

        swap(arr[low], arr[high]);
        return low;
    }

    static int recurseFind(vector<int> &arr, const int k, int start, int end) {
        int p = partition(arr, start, end);

        if (p > k - 1)
            return recurseFind(arr, k, start, p - 1);
        else if (p < k - 1)
            return recurseFind(arr, k, p + 1, end);
        else
            return arr[p];
    }

public:
    static int find(const vector<int> &arr, const int k) {
        auto dup = arr;
        return recurseFind(dup, k, 0, (int) arr.size() - 1);
    }
};

/*
 * Given an unsorted array of numbers, find Kth smallest number in it.
 * Please note that it is the Kth smallest number in the sorted order, not the Kth distinct element.
 */
int main() {
    cout << KthSmallestNumber::find({1, 5, 12, 2, 11, 5}, 3) << endl;
    cout << KthSmallestNumber::find({1, 5, 12, 2, 11, 5}, 4) << endl;
    cout << KthSmallestNumber::find({5, 12, 11, -1, 12}, 3) << endl;
}
