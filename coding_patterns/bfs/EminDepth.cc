#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;

    explicit Node(int val, Node *left = nullptr, Node *right = nullptr)
            : val(val), left(left), right(right) {}
};

int minDepth(Node *root) {
    int depth = 0;

    if (!root)
        return depth;

    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        ++depth;
        for (int i = 0, size = queue.size(); i < size; ++i) {
            Node *curr = queue.front();
            queue.pop();

            if (!curr->left && !curr->right)
                return depth;

            if (curr->left)
                queue.push(curr->left);
            if (curr->right)
                queue.push(curr->right);
        }
    }

    return depth;
}

/*
 * Given a binary tree, populate an array to represent the averages of all of its levels
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << minDepth(root) << endl;
}
