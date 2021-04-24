#include <bits/stdc++.h>

using namespace std;

bool isHappyNumber(int number);

int nextState(int number);

/*
 * Any number will be called a happy number if,
 * after repeatedly replacing it with a number equal to the sum of the square of all of its digits,
 * leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’.
 * Instead, they will be stuck in a cycle of numbers which does not include ‘1’
 */
int main() {
    cout << boolalpha << isHappyNumber(123) << endl;
}

bool isHappyNumber(int number) {
    int slow = number, fast = number;

    do {
        slow = nextState(slow);
        fast = nextState(nextState(fast));
    } while (slow != fast && fast != 1);

    return fast == 1;
}

int nextState(const int number) {
    static unordered_map<int, int> cache;

    if (cache.find(number) != cache.end())
        return cache[number];

    int result = 0, num = number;
    while (num) {
        int temp = num % 10;
        num /= 10;
        result += temp * temp;
    }

    return cache[number] = result;
}
