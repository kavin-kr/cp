#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;

    explicit Node(int val, Node *left = nullptr, Node *right = nullptr)
            : val(val), left(left), right(right) {}
};

Node *levelOrderSuccessor(Node *root, int key) {
    if (!root)
        return root;

    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node *curr = queue.front();
        queue.pop();

        if (curr->val == key)
            break;

        if (curr->left)
            queue.push(curr->left);
        if (curr->right)
            queue.push(curr->right);
    }

    if (queue.empty())
        return nullptr;

    return queue.front();
}

/*
 * Given a binary tree and a node, find the level order successor of the given node in the tree.
 * The level order successor is the node that appears right after the given node in the level order traversal.
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Node *successor = levelOrderSuccessor(root, 9);
    cout << (successor ? successor->val : -1) << endl;
}
