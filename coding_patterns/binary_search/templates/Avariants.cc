#include <bits/stdc++.h>

using namespace std;

// there should be no duplicate values in sorted input array
int find(vector<int> &arr, int key) {
    int res = -1;

    for (int start = 0, end = (int) arr.size() - 1; start <= end;) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            res = mid;
            break;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return res;
}

// lower bound
int findFirst(vector<int> &arr, int key) {
    int res = -1;

    for (int start = 0, end = (int) arr.size() - 1; start <= end;) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            res = mid;
            end = mid - 1;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return res;
}

int findLast(vector<int> &arr, int key) {
    int res = -1;

    for (int start = 0, end = (int) arr.size() - 1; start <= end;) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            res = mid;
            start = mid + 1;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return res;
}

// upper bound
int findLeastGreater(vector<int> &arr, int key) {
    int res = -1;

    for (int start = 0, end = (int) arr.size() - 1; start <= end;) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            start = mid + 1;
        } else if (arr[mid] > key) {
            res = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return res;
}

int findGreatestLesser(vector<int> &arr, int key) {
    int res = -1;

    for (int start = 0, end = (int) arr.size() - 1; start <= end;) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            end = mid - 1;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            res = mid;
            start = mid + 1;
        }
    }

    return res;
}

/*
 * https://www.geeksforgeeks.org/variants-of-binary-search/
 */
int main() {
    vector<int> arr;
    int key;

    arr = {1, 2, 4, 6, 8, 23};
    key = 8;
    cout << "find: " << find(arr, key) << endl;

    arr = {1, 2, 2, 2, 6, 8};
    key = 2;
    cout << "findFirst: " << findFirst(arr, key) << endl;

    arr = {1, 2, 2, 2, 6, 8};
    key = 2;
    cout << "findLast: " << findLast(arr, key) << endl;

    arr = {1, 2, 2, 2, 6, 8};
    key = 2;
    cout << "findLeastGreater: " << findLeastGreater(arr, key) << endl;

    arr = {1, 2, 2, 2, 6, 8};
    key = 2;
    cout << "findGreatestLesser: " << findGreatestLesser(arr, key) << endl;
}
