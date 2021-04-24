#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *next;

    explicit Node(int value, Node *next = nullptr)
            : value(value), next(next) {}
};

bool isPalindrome(Node *head);

Node *middleOfList(Node *head);

Node *reverse(Node *head);

/*
 * Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.
 * Your algorithm should use constant space and the input LinkedList
 * should be in the original form once the algorithm is finished.
 * The algorithm should have O(N) time complexity where ‘N’ is the number of nodes in the LinkedList.
 */
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(23);
    head->next->next->next->next->next = new Node(1);

    cout << boolalpha << isPalindrome(head) << endl;

    for (Node *temp = head; temp; temp = temp->next)
        cout << temp->value << " ";
}

bool isPalindrome(Node *head) {
    Node *middle = middleOfList(head);
    Node *secHead = reverse(middle);

    bool result = true;
    Node *h1 = head, *h2 = secHead;
    while (h1 && h2) {
        if (h1->value != h2->value) {
            result = false;
            break;
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    reverse(secHead);

    return result;
}

Node *middleOfList(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverse(Node *head) {
    Node *prev = nullptr;
    while (head) {
        Node *temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
    }
    return prev;
}
