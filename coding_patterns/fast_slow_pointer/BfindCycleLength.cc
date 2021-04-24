#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *next;

    explicit Node(int value, Node *next = nullptr)
            : value(value), next(next) {}
};

int findCycleLength(Node *head);

/*
 * Given the head of a Singly LinkedList,
 * write a function to determine if the LinkedList has a cycle in it or not
 */
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->next->next->next->next = head->next;

    cout << findCycleLength(head) << endl;
}

// floyd cycle finding algo
int findCycleLength(Node *head) {
    Node *slow = head, *fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) {
            int len = 0;
            do {
                slow = slow->next;
                ++len;
            } while (slow != fast);
            return len;
        }
    }

    return 0;
}
