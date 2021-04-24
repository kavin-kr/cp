#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *next;

    explicit Node(int value, Node *next = nullptr)
            : value(value), next(next) {}
};

Node *middleOfList(Node *head);

/*
 * Given the head of a Singly LinkedList, write a method to return the middle node of the LinkedList.
 * If the total number of nodes in the LinkedList is even, return the second middle node.
 */
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    Node *middle = middleOfList(head);
    cout << (middle ? middle->value : -1) << endl;
}

Node *middleOfList(Node *head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
