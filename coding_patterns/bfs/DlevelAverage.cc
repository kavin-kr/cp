#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
    out << "[";
    for (int i = 0, len = arr.size(); i < len; ++i)
        out << arr[i] << (i == len - 1 ? "" : ", ");
    out << "]";
    return out;
}

struct Node {
    int val;
    Node *left, *right;

    explicit Node(int val, Node *left = nullptr, Node *right = nullptr)
            : val(val), left(left), right(right) {}
};

vector<double> levelAverage(Node *root) {
    vector<double> result;

    if (!root)
        return result;

    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            Node *curr = queue.front();
            queue.pop();

            sum += curr->val;

            if (curr->left)
                queue.push(curr->left);
            if (curr->right)
                queue.push(curr->right);
        }
        result.emplace_back(sum/size);
    }

    return result;
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

    cout << levelAverage(root) << endl;
}
