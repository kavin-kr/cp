#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left = nullptr, *right = nullptr;

    explicit Node(int val) : val(val) {}
};

class MaximumPathSum {
    static int findMaxSumHelper(Node *curr, int &maxSum) {
        if (!curr)
            return 0;

        // ignore branch with neg sum as max tree sum will be set in maxSum
        int left = max(0, findMaxSumHelper(curr->left, maxSum));
        int right = max(0, findMaxSumHelper(curr->right, maxSum));

        maxSum = max(maxSum, curr->val + left + right);

        return curr->val + max(left, right);
    }

public:
    static long findMaxSum(Node *root) {
        int maxSum = numeric_limits<int>::min();
        findMaxSumHelper(root, maxSum);
        return lround(maxSum);
    }
};

/*
 * Find the path with the maximum sum in a given binary tree.
 * Write a function that returns the maximum sum.
 * A path can be defined as a sequence of nodes between any two nodes and doesn't necessarily pass through the root.
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << MaximumPathSum::findMaxSum(root) << endl;

    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->left = new Node(9);

    cout << MaximumPathSum::findMaxSum(root) << endl;

    root = new Node(-1);
    root->left = new Node(-3);

    cout << MaximumPathSum::findMaxSum(root) << endl;
}
