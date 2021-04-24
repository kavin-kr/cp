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

Node *rotateList(Node *head, int k) {
    if (!head || k < 1)
        return nullptr;

    int len = 1;
    Node *lastNode = head;
    while (lastNode->next) {
        lastNode = lastNode->next;
        ++len;
    }

    lastNode->next = head;
    int skipLen = len - (k % len);

    lastNode = head;
    for (int i = 0; i < skipLen - 1; ++i)
        lastNode = lastNode->next;

    head = lastNode->next;
    lastNode->next = nullptr;

    return head;
}

/*
 * Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the right by ‘k’ nodes.
 */
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << head << endl;
    cout << rotateList(head, 3) << endl;
}
