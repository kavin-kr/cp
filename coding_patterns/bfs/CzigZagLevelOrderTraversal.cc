#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &arr) {
    out << "[";
    for (int i = 0, len = arr.size(); i < len; ++i)
        out << arr[i] << (i == len - 1 ? "" : ", ");
    out << "]";
    return out;
}

ostream &operator<<(ostream &out, const vector<vector<int>> &arr) {
    out << "[";
    for (int i = 0, len = arr.size(); i < len; ++i)
        out << arr[i] << (i == len - 1 ? "" : ", \n");
    out << "]";
    return out;
}

struct Node {
    int val;
    Node *left, *right;

    explicit Node(int val, Node *left = nullptr, Node *right = nullptr)
            : val(val), left(left), right(right) {}
};

vector<vector<int>> zigZagLevelOrderTraversal(Node *root, bool zig = true) {
    vector<vector<int>> result;

    if (!root)
        return result;

    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            Node *curr = queue.front();
            queue.pop();

            if (zig)
                arr[i] = curr->val;
            else
                arr[size - 1 - i] = curr->val;

            if (curr->left)
                queue.push(curr->left);
            if (curr->right)
                queue.push(curr->right);
        }
        result.push_back(arr);
        zig = !zig;
    }

    return result;
}

/*
 * Given a binary tree, populate an array to represent its zigzag level order traversal.
 * You should populate the values of all nodes of the first level from left to right,
 * then right to left for the next level and keep alternating in the same manner for the following levels
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << zigZagLevelOrderTraversal(root, false) << endl;
}
