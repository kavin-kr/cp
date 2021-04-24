#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *next;

    explicit Node(int value, Node *next = nullptr)
            : value(value), next(next) {}
};

void printList(Node *head) {
    for (Node *temp = head; temp; temp = temp->next)
        cout << temp->value << " ";
    cout << endl;
}

Node *middleOfList(Node *head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverseList(Node *head) {
    Node *prev = nullptr;
    while(head) {
        Node *temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
    }
    return prev;
}

void rearrangeList(Node *head) {
    Node *middle = middleOfList(head);
    Node *secHead = reverseList(middle);

    while(head && secHead) {
        Node *h1 = head, *h2 = secHead;
        head = head->next;
        secHead = secHead->next;

        h1->next = h2;
        h2->next = head;
    }

    if(head)
        head->next = nullptr;
}

/*
 * Given the head of a Singly LinkedList, write a method to modify the LinkedList such that
 * the nodes from the second half of the LinkedList are inserted
 * alternately to the nodes from the first half in reverse order.
 * So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null,
 * your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null
 */
int main() {
    Node *head = new Node(1);
    head->next = new Node(24);
    head->next->next = new Node(31);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(23);
    head->next->next->next->next->next = new Node(17);

    printList(head);
    rearrangeList(head);
    printList(head);
}
