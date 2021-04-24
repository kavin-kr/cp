#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;

    explicit Node(int val)
            : val(val), left(nullptr), right(nullptr) {}
};

vector<Node *> rightView(Node *root) {
    vector<Node *> result;
    if (!root)
        return result;

    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node *lastNode = nullptr;
        for (int i = 0, size = queue.size(); i < size; ++i) {

            Node *curr = queue.front();
            queue.pop();

            lastNode = curr;

            if (curr->left)
                queue.push(curr->left);
            if (curr->right)
                queue.push(curr->right);
        }
        result.push_back(lastNode);
    }

    return result;
}

/*
 * Given a binary tree, return an array containing nodes in its right view.
 * The right view of a binary tree is the set of nodes visible when the tree is seen from the right side
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    for (auto &tmp: rightView(root))
        cout << tmp->val << " ";
    cout << endl;
}
