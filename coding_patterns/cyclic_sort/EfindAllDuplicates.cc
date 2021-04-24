#include <bits/stdc++.h>

using namespace std;

vector<int> findAllDuplicates(vector<int> &arr) {
    for (int i = 0; i < arr.size();)
        if (arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            ++i;

    vector<int> result;
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] != i + 1)
            result.emplace_back(arr[i]);

    return result;
}

/*
 * We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’.
 * The array has some duplicates, find all the duplicate numbers without using any extra space
 */
int main() {
    vector<int> arr = {5, 4, 7, 2, 3, 5, 3};
    for (int &x: findAllDuplicates(arr))
        cout << x << " ";
}
