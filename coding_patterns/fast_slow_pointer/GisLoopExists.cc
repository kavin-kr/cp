#include <bits/stdc++.h>

using namespace std;

int findNextIndex(const vector<int> &arr, bool isForward, int currIndex) {
    bool direction = (arr[currIndex] >= 0);
    if (direction != isForward)
        return -1;

    int nextIndex = (currIndex + arr[currIndex] + arr.size()) % arr.size();

    return nextIndex == currIndex ? -1 : nextIndex;
}

bool isLoopExists(const vector<int> &arr) {
    // check each element as head
    for (int i = 0; i < arr.size(); ++i) {
        bool isForward = (arr[i] >= 0);
        int slow = i, fast = i;

        do {
            slow = findNextIndex(arr, isForward, slow);
            fast = findNextIndex(arr, isForward, fast);
            if (fast != -1)
                fast = findNextIndex(arr, isForward, fast);
        } while (slow != -1 && fast != -1 && slow != fast);

        if (slow != -1 && slow == fast)
            return true;
    }

    return false;
}

/*
 * We are given an array containing positive and negative numbers.
 * Suppose the array contains a number ‘M’ at a particular index.
 * Now, if ‘M’ is positive we will move forward ‘M’ indices
 * and if ‘M’ is negative move backwards ‘M’ indices.
 *
 * You should assume that the array is circular which means two things:
 *  1.  If, while moving forward, we reach the end of the array,
 *      we will jump to the first element to continue the movement.
 *  2.  If, while moving backward, we reach the beginning of the array,
 *      we will jump to the last element to continue the movement.
 *
 * Write a method to determine if the array has a cycle.
 * The cycle should have more than one element and should follow one direction
 * which means the cycle should not contain both forward and backward movements.
 */
int main() {
    cout << boolalpha << isLoopExists({1, 2, -1, 2, 2}) << endl;
}
