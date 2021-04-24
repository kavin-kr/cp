#include <bits/stdc++.h>

using namespace std;

int minCostToConnectRopes(const vector<int> &arr) {
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

    int result = 0;
    while (minHeap.size() > 1) {
        int tmp = minHeap.top();
        minHeap.pop();

        tmp += minHeap.top();
        minHeap.pop();

        result += tmp;
        minHeap.push(tmp);
    }

    return result;
}

/*
 * Given ‘N’ ropes with different lengths,
 * we need to connect these ropes into one big rope with minimum cost.
 * The cost of connecting two ropes is equal to the sum of their lengths
 */
int main() {
    cout << minCostToConnectRopes({1, 3, 11, 5}) << endl;
    cout << minCostToConnectRopes({3, 4, 5, 6}) << endl;
    cout << minCostToConnectRopes({1, 3, 11, 5, 2}) << endl;
}
