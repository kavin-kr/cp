#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *next;

    explicit Node(int value, Node *next = nullptr) : value(value), next(next) {}
};

ostream &operator<<(ostream &out, const Node *head) {
    out << "[";
    while (head) {
        out << head->value << (head->next ? ", " : "");
        head = head->next;
    }
    out << "]";
    return out;
}

Node *reverseAlternateKElement(Node *head, int k) {
    if (k < 1)
        return nullptr;
    if (k == 1)
        return head;

    for (Node *curr = head, *prev = nullptr; curr;) {
        Node *lastCurr = curr, *lastPrev = prev;
        for (int i = 0; curr && i < k; ++i) {
            Node *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        lastCurr->next = curr;
        if (lastPrev)
            lastPrev->next = prev;
        else
            head = prev;

        for (int i = 0; curr && i < k; ++i) {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

/*
 * Given the head of a LinkedList and a number ‘k’, 
 * reverse every alternating ‘k’ sized sub-list starting from the head.
 * If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.
 */
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    cout << head << endl;

    cout << reverseAlternateKElement(head, 2) << endl;
}
