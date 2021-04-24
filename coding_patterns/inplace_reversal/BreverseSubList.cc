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
        cout << head->value << (head->next ? ", " : "");
        head = head->next;
    }
    out << "]";
    return out;
}

Node *reverseSubList(Node *head, int p, int q) {
    if (!head || p > q)
        return nullptr;
    if(p == q)
        return head;

    Node *curr = head, *prev = nullptr;
    for (int i = 0; curr && i < p - 1; ++i) {
        prev = curr;
        curr = curr->next;
    }

    Node *lastOfSublist = curr, *lastOfFirst = prev;
    for (int i = 0; curr && i < q - p + 1; ++i) {
        Node *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }

    lastOfSublist->next = curr;
    if (lastOfFirst)
        lastOfFirst->next = prev;
    else
        head = prev;

    return head;
}

/*
 * Given the head of a LinkedList and two positions ‘p’ and ‘q’,
 * reverse the LinkedList from position ‘p’ to ‘q’. [1 based index]
 */
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << head << endl;

    cout << reverseSubList(head, 2, 4) << endl;

    // Reverse the first ‘k’ elements of a given LinkedList
    // Solution:
    //      This problem can be easily converted to our parent problem;
    //      to reverse the first ‘k’ nodes of the list, we need to pass p=1 and q=k

    // Given a LinkedList with ‘n’ nodes, reverse it based on its size in the following way:
    //  1. If ‘n’ is even, reverse the list in a group of n/2 nodes.
    //  2. If n is odd, keep the middle node as it is, reverse the first ‘n/2’ nodes and reverse the last ‘n/2’ nodes.
    // Solution:
    // When ‘n’ is even we can perform the following steps:
    //      Reverse first ‘n/2’ nodes: head = reverse(head, 1, n/2)
    //      Reverse last ‘n/2’ nodes: head = reverse(head, n/2 + 1, n)
    // When ‘n’ is odd, our algorithm will look like:
    //      head = reverse(head, 1, n/2)
    //      head = reverse(head, n/2 + 2, n)
}
