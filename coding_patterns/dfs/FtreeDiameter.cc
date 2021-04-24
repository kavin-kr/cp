#include <bits/stdc++.h>

using namespace std;

constexpr double NEG_INFINITY = -numeric_limits<double>::infinity();

struct Node {
    int val;
    Node *left = nullptr, *right = nullptr;

    explicit Node(int val) : val(val) {}
};

class TreeDiameter {
    struct DiaData {
        double tree, branch;
    };

    static DiaData findDiameterHelper(Node *curr) {
        if (!curr)
            return {NEG_INFINITY, NEG_INFINITY};

        if (!curr->left && !curr->right)
            return {NEG_INFINITY, 1};

        DiaData left = findDiameterHelper(curr->left);
        DiaData right = findDiameterHelper(curr->right);

        double tree = max(max(left.tree, right.tree), 1 + left.branch + right.branch);
        double branch = 1 + max(left.branch, right.branch);

        return {tree, branch};
    }

public:
    static long findDiameter(Node *root) {
        DiaData result = findDiameterHelper(root);
        return lround(result.tree);
    }
};

class TreeDiameter2 {
    static int findDiameterHelper(Node *curr, int &treeDiameter) {
        if (!curr)
            return 0;

        int left = findDiameterHelper(curr->left, treeDiameter);
        int right = findDiameterHelper(curr->right, treeDiameter);

        treeDiameter = max(treeDiameter, 1 + left + right);

        return 1 + max(left, right);
    }

public:
    static int findDiameter(Node *root) {
        int treeDiameter = 0;
        findDiameterHelper(root, treeDiameter);
        return treeDiameter;
    }
};

/*
 * Given a binary tree, find the length of its diameter.
 * The diameter of a tree is the number of nodes on the longest path between any two leaf nodes.
 * The diameter of a tree may or may not pass through the root.
 * Note: You can always assume that there are at least two leaf nodes in the given tree
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << TreeDiameter::findDiameter(root) << " " << TreeDiameter2::findDiameter(root) << endl;

    root->left->left = nullptr;
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->left->right->left = new Node(10);
    root->right->right->left->left = new Node(11);

    cout << TreeDiameter::findDiameter(root) << " " << TreeDiameter2::findDiameter(root) << endl;
}
