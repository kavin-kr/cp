#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right, *next;

    explicit Node(int val)
            : val(val), left(nullptr), right(nullptr), next(nullptr) {}
};

void printLevelOrderUsingNext(Node *root) {
    Node *nextRoot = root;
    while (nextRoot) {
        Node *curr = nextRoot;
        nextRoot = nullptr;
        while (curr) {
            if (!nextRoot) {
                if (curr->left)
                    nextRoot = curr->left;
                else if (curr->right)
                    nextRoot = curr->right;
            }
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
}

void connectLevelOrderSiblings(Node *root) {
    if (!root)
        return;

    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node *prev = nullptr;
        for (int i = 0, size = queue.size(); i < size; ++i) {
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
}

/*
 * Given a binary tree, connect each node with its level order successor.
 * The last node of each level should point to a null node.
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);


    connectLevelOrderSiblings(root);

    printLevelOrderUsingNext(root);
}
