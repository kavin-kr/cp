#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;

    explicit Node(int val) : val(val), next(nullptr) {}
};

Node *createList(const initializer_list<int> &items) {
    Node *head = nullptr, *tail = nullptr;
    for (auto &x: items) {
        if (!head) {
            head = tail = new Node(x);
        } else {
            tail->next = new Node(x);
            tail = tail->next;
        }
    }
    return head;
}

int kthSmallest(const initializer_list<Node *> &heads, const int k) {
    struct GreaterValCompare {
        bool operator()(const Node *const &x, const Node *const &y) {
            return x->val > y->val;
        }
    };
    priority_queue<Node *, vector<Node *>, GreaterValCompare> minHeap;

    for (auto &node: heads) {
        if (node)
            minHeap.push(node);
    }

    for (int count = 0; !minHeap.empty();) {
        Node *top = minHeap.top();
        minHeap.pop();

        if (++count == k)
            return top->val;

        if (top->next)
            minHeap.push(top->next);
    }

    return -1;
}

/*
 * Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays
 */
int main() {
    Node *h1 = createList({2, 6, 8});
    Node *h2 = createList({3, 6, 7});
    Node *h3 = createList({1, 3, 4});

    cout << kthSmallest({h1, h2, h3}, 5) << endl;
}
