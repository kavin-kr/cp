#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right, *next;

    explicit Node(int val)
            : val(val), left(nullptr), right(nullptr), next(nullptr) {}
};

void connectAllSiblings(Node *root) {
    if (!root)
        return;

    queue<Node *> queue;
    queue.push(root);
    Node *prev = nullptr;
    while (!queue.empty()) {
        Node *curr = queue.front();
        queue.pop();

        if (prev)
            prev->next = curr;
        prev = curr;

        if (curr->left)
            queue.push(curr->left);
        if (curr->right)
            queue.push(curr->right);
    }
}

/*
 * Given a binary tree, connect each node with its level order successor.
 * The last node of each level should point to the first node of the next level.
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    connectAllSiblings(root);

    for (Node *tmp = root; tmp; tmp = tmp->next)
        cout << tmp->val << " ";
    cout << endl;
}
