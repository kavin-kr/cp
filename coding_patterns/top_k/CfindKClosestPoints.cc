#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    int distanceFromOrigin() const {
        // ignore sqrt
        return (x * x) + (y * y);
    }

    bool operator<(const Point &p) const {
        return this->distanceFromOrigin() < p.distanceFromOrigin();
    }
};

vector<Point> findKClosestPoints(const vector<Point> &arr, int k) {
    if (k <= 0)
        return {};
    if (k >= arr.size())
        return arr;

    vector<Point> maxHeap(arr.begin(), arr.begin() + k);
    make_heap(maxHeap.begin(), maxHeap.end());

    for (int i = k; i < arr.size(); ++i)
        if (arr[i] < maxHeap.front()) {
            pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back();
            maxHeap.push_back(arr[i]);
            push_heap(maxHeap.begin(), maxHeap.end());
        }

    return maxHeap;
}

ostream &operator<<(ostream &out, const vector<Point> &points) {
    out << "[";
    for (int i = 0, size = points.size(); i < size; ++i)
        out << "[" << points[i].x << ", " << points[i].y << "]" << (i + 1 == size ? "" : "\n");
    out << "]";
    return out;
}

/*
 * Given an array of points in the a 2D2D plane, find ‘K’ closest points to the origin.
 */
int main() {
    cout << findKClosestPoints({{1, 2},
                                {1, 3}}, 1) << endl << endl;

    cout << findKClosestPoints({{1, 3},
                                {3, 4},
                                {2, -1}}, 2) << endl << endl;
}
