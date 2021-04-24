#include <bits/stdc++.h>

using namespace std;

class LFUCache {
    struct Node {
        int key, value, freq, timeStamp;

        Node(int key, int value, int timeStamp) : key(key), value(value), timeStamp(timeStamp), freq(1) {}
    };

    int timer, size;
    vector<Node *> pq;
    unordered_map<int, int> mp;

    void nodeSwap(int idx1, int idx2) {
        swap(pq[idx1], pq[idx2]);
        // the nodes are swapped now hence below will work
        mp[pq[idx1]->key] = idx1;
        mp[pq[idx2]->key] = idx2;
    }

    static bool less(const Node *const lhs, const Node *const rhs) {
        if (lhs->freq == rhs->freq)
            return lhs->timeStamp < rhs->timeStamp;
        return lhs->freq < rhs->freq;
    }

    void bubbleUp(int idx) {
        while (idx > 1 && less(pq[idx], pq[idx / 2])) {
            nodeSwap(idx / 2, idx);
            idx /= 2;
        }
    }

    void bubbleDown(int idx) {
        int j = 2 * idx;
        while (j <= size) {
            if (j < size && less(pq[j + 1], pq[j]))
                ++j;
            if (!less(pq[j], pq[idx]))
                break;
            nodeSwap(j, idx);
            idx = j;
        }
    }

public:
    LFUCache(int size) : size(size), timer(0) {
        pq.push_back(new Node(-1, -1, -1));
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        int idx = mp[key];
        int value = pq[idx]->value;
        pq[idx]->freq++;
        pq[idx]->timeStamp = ++timer;
        bubbleDown(idx);

        return value;
    }

    void set(int key, int value) {
        if (size <= 0)
            return;

        if (mp.count(key)) {
            pq[mp[key]]->value = value;
            get(key);
        } else {
            if (pq.size() - 1 == size) {
                int oldKey = pq[1]->key;
                mp.erase(oldKey);
                pq[1] = new Node(key, value, ++timer);
                mp[key] = 1;
                bubbleDown(1);
            } else {
                pq.push_back(new Node(key, value, ++timer));
                mp[key] = pq.size() - 1;
                bubbleUp(pq.size() - 1);
            }
        }
    }

};

/*
 * https://leetcode.com/problems/lfu-cache/discuss/94673/c-solution-with-detailed-explanations-using-indexed-priority-queue-ie-hashmap-priority-queue
 */
int main() {
}
