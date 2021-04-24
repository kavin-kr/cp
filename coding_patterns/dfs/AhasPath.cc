#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left = nullptr, *right = nullptr;

    explicit Node(int val) : val(val) {}
};

bool hasPath(Node *root, int targetSum) {
    if (!root)
        return false;

    if ((!root->left && !root->right) && root->val == targetSum)
        return true;

    return hasPath(root->left, targetSum - root->val)
           || hasPath(root->right, targetSum - root->val);
}

/*
 * Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf
 * such that the sum of all the node values of that path equals ‘S’
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    cout << boolalpha << hasPath(root, 7) << endl;
}
