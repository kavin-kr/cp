#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;

    explicit Node(int val) : val(val), next(nullptr) {}
};

ostream &operator<<(ostream &out, const Node *const head) {
    out << "[";
    for (const Node *tmp = head; tmp; tmp = tmp->next)
        out << tmp->val << (tmp->next ? ", " : "");
    out << "]";
    return out;
}

Node *mergeList(const initializer_list<Node *> &heads) {
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

    Node *resHead = nullptr, *resTail = nullptr;
    while (!minHeap.empty()) {
        Node *top = minHeap.top();
        minHeap.pop();

        if (!resHead) {
            resHead = top;
            resTail = top;
        } else {
            resTail->next = top;
            resTail = top;
        }

        if (top->next) {
            minHeap.push(top->next);
        }
    }

    return resHead;
}

/*
 * Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
 */
int main() {
    Node *h1 = new Node(2);
    h1->next = new Node(6);
    h1->next->next = new Node(8);

    Node *h2 = new Node(3);
    h2->next = new Node(6);
    h2->next->next = new Node(7);

    Node *h3 = new Node(1);
    h3->next = new Node(3);
    h3->next->next = new Node(4);
    h3->next->next->next = new Node(34);

    cout << mergeList({h1, h2, h3}) << endl;
}
