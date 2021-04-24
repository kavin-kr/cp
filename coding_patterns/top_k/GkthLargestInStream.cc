#include <bits/stdc++.h>

using namespace std;

class KthLargestInStream {
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargestInStream(const vector<int> &arr, int k) : k(k) {
        for (auto &x: arr)
            add(x);
    }

    int add(int num) {
        minHeap.push(num);
        if (minHeap.size() > k)
            minHeap.pop();

        return minHeap.top();
    }
};

/*
 * Design a class to efficiently find the Kth largest element in a stream of numbers.
 * The class should have the following two things:
 *  1. The constructor of the class should accept an integer array
 *     containing initial numbers from the stream and an integer ‘K’.
 *  2. The class should expose a function add(int num) which will store
 *     the given number and return the Kth largest number
 */
int main() {
    KthLargestInStream stream = KthLargestInStream({3, 1, 5, 12, 2, 11}, 4);
    cout << stream.add(6) << endl;
    cout << stream.add(13) << endl;
    cout << stream.add(4) << endl;
}
