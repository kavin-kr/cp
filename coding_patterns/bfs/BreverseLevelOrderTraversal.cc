#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &arr) {
    out << "[";
    for (int i = 0, len = arr.size(); i < len; ++i)
        out << arr[i] << (i == len - 1 ? "" : ", ");
    out << "]";
    return out;
}

ostream &operator<<(ostream &out, const deque<vector<int>> &arr) {
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

deque<vector<int>> reverseLevelOrderTraversal(Node *root) {
    deque<vector<int>> result;

    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        vector<int> arr;

        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node *curr = queue.front();
            queue.pop();

            arr.push_back(curr->val);

            if (curr->left)
                queue.push(curr->left);
            if (curr->right)
                queue.push(curr->right);
        }

        result.push_front(arr);
    }

    return result;
}

/*
 * Given a binary tree, populate an array to represent its level-by-level traversal in 
 * reverse order, i.e., the lowest level comes first. 
 * You should populate the values of all nodes in each level from left to right in separate sub-arrays
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << reverseLevelOrderTraversal(root) << endl;
}