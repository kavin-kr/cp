#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left = nullptr, *right = nullptr;

    explicit Node(int val) : val(val) {}
};

class FindAllTreePaths {
    static void findPathsHelper(Node *curr, int targetSum, vector<int> &currPath, vector<vector<int>> &result) {
        if (!curr)
            return;

        currPath.emplace_back(curr->val);

        if ((!curr->left && !curr->right) && curr->val == targetSum) {
            result.push_back(currPath);
        } else {
            findPathsHelper(curr->left, targetSum - curr->val, currPath, result);
            findPathsHelper(curr->right, targetSum - curr->val, currPath, result);
        }

        currPath.pop_back();
    }

public:
    static vector<vector<int>> findPaths(Node *root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currPath;

        findPathsHelper(root, targetSum, currPath, result);

        return result;
    }
};

/*
 * Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that
 * the sum of all the node values of each path equals ‘S’.
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(2);
    root->right->right->right = new Node(1);

    for (auto &currPath: FindAllTreePaths::findPaths(root, 7)) {
        for (auto &x: currPath)
            cout << x << " ";
        cout << "\n";
    }
}
