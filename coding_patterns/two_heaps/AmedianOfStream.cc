#include <bits/stdc++.h>

using namespace std;

class MedianOfStream {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianOfStream &insertNum(int num) {
        if (maxHeap.empty() || num < maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if (maxHeap.size() > 1 + minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            // always move the extra one to the maxHeap
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        return *this;
    }

    double findMedian() {
        if (maxHeap.empty() && minHeap.empty())
            throw runtime_error("heap not populated");

        if (maxHeap.size() == minHeap.size())
            return 0.5 * (maxHeap.top() + minHeap.top());

        return maxHeap.top();
    }
};

/*
 * Design a class to calculate the median of a number stream. The class should have the following two methods:
 * 1. insertNum(int num): stores the number in the class
 * 2. findMedian(): returns the median of all numbers inserted in the class
 * If the count of numbers inserted in the class is even, the median will be the average of the middle two numbers
 */
int main() {
    MedianOfStream median;

    // cout << median.findMedian() << endl;

    cout << median
            .insertNum(3)
            .insertNum(1)
            .findMedian() << endl;
    cout << median
            .insertNum(5)
            .findMedian() << endl;
    cout << median
            .insertNum(4)
            .findMedian() << endl;
}
