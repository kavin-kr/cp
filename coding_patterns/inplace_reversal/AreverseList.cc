#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int value, Node *next = nullptr) : value(value), next(next) {}
};

Node *reverseList(Node *head) {
    Node *prev = nullptr;
    while (head) {
        Node *tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }
    return prev;
}

/*
 * Given the head of a Singly LinkedList, reverse the LinkedList.
 * Write a function to return the new head of the reversed LinkedList.
 */
int main() {
    Node *head = new Node(3);
    head->next = new Node(6);
    head->next->next = new Node(23);
    head->next->next->next = new Node(8);

    head = reverseList(head);
    for (Node *tmp = head; tmp; tmp = tmp->next)
        cout << tmp->value << " ";
}
