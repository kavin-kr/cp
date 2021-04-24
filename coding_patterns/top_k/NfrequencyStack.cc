#include <bits/stdc++.h>

using namespace std;

class FrequencyStack {
    struct Item {
        int val, freq, seq;

        Item(int val, int freq, int seq) : val(val), freq(freq), seq(seq) {}

        bool operator<(const Item &x) const {
            if (freq != x.freq)
                return freq < x.freq;
            return seq < x.seq;
        }
    };

    int seqNum = 0;
    unordered_map<int, int> freqMap;
    priority_queue<Item> maxHeap;

public:
    FrequencyStack &push(int num) {
        maxHeap.emplace(num, ++freqMap[num], seqNum++);
        return *this;
    }

    int pop() {
        int num = maxHeap.top().val;
        maxHeap.pop();

        if (freqMap[num] > 1)
            --freqMap[num];
        else
            freqMap.erase(num);

        return num;
    }
};

/*
 * Design a class that simulates a Stack data structure, implementing the following two operations:
 *  1. push(int num): Pushes the number ‘num’ on the stack.
 *  2. pop(): Returns the most frequent number in the stack.
 *     If there is a tie, return the number which was pushed later
 */
int main() {
    FrequencyStack freqStack;
    freqStack
            .push(1)
            .push(2)
            .push(3)
            .push(2)
            .push(1)
            .push(2)
            .push(5);

    cout << freqStack.pop() << endl;
    cout << freqStack.pop() << endl;
    cout << freqStack.pop() << endl;
}
