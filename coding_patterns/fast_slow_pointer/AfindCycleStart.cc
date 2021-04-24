#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *next;

    explicit Node(int value, Node *next = nullptr)
            : value(value), next(next) {}
};

Node *findCycleStart(Node *head);

/*
 * Given the head of a Singly LinkedList that contains a cycle,
 * write a function to find the starting node of the cycle
 */
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->next->next->next->next = head;

    Node *cycleStart = findCycleStart(head);
    cout << (cycleStart ? cycleStart->value : -1) << endl;
}

// https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
Node *findCycleStart(Node *head) {
    Node *slow = head, *fast = head;

    while (fast && fast->value) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}
