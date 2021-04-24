#include <bits/stdc++.h>

using namespace std;

char nextLetter(const vector<char> &arr, const char key) {
    if (arr.empty())
        return '!';

    int start = 0, end = arr.size();
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= key)
            start = mid + 1;
        else
            end = mid;
    }

    return arr[start % arr.size()];
}

/*
 * Given an array of lowercase letters sorted in ascending order,
 * find the smallest letter in the given array greater than a given ‘key’.
 * Assume the given array is a circular list, which means that the last letter
 * is assumed to be connected with the first letter.
 * This also means that the smallest letter in the given array is greater than
 * the last letter of the array and is also the first letter of the array.
 * Write a function to return the next letter of the given ‘key’
 */
int main() {
    cout << nextLetter({'a', 'c', 'f', 'h'}, 'f') << endl;
    cout << nextLetter({'a', 'c', 'f', 'h'}, 'b') << endl;
    cout << nextLetter({'a', 'c', 'f', 'h'}, 'm') << endl;
    cout << nextLetter({'a', 'c', 'f', 'h'}, 'h') << endl;
}
