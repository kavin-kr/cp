#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left = nullptr, *right = nullptr;

    explicit Node(int val) : val(val) {}
};

class CountAllPathSumRecurse {
    static void countPathsHelper(Node *currNode, int currSum, const int &targetSum, int &count) {
        if (!currNode || currSum > targetSum)
            return;

        if (currSum + currNode->val == targetSum) {
            ++count;
        } else {
            countPathsHelper(currNode->left, currSum + currNode->val, targetSum, count);
            countPathsHelper(currNode->right, currSum + currNode->val, targetSum, count);
            countPathsHelper(currNode->left, 0, targetSum, count);
            countPathsHelper(currNode->right, 0, targetSum, count);
        }
    }

public:
    static int countPaths(Node *root, int targetSum) {
        int count = 0;
        countPathsHelper(root, 0, targetSum, count);
        return count;
    }
};

class CountAllPathSumBacktrack {
    static int countPathsHelper(Node *currNode, int &target, vector<int> &currPath) {
        if (!currNode)
            return 0;

        currPath.push_back(currNode->val);

        int sum = 0, count = 0;
        // sum of sub-paths ending at curr node
        for (auto itr = currPath.rbegin(); itr != currPath.rend(); ++itr) {
            sum += *itr;

            if (sum == target)
                ++count;
        }
        count += countPathsHelper(currNode->left, target, currPath);
        count += countPathsHelper(currNode->right, target, currPath);

        currPath.pop_back();
        return count;
    }

public:
    static int countPaths(Node *root, int target) {
        vector<int> currPath;
        return countPathsHelper(root, target, currPath);
    }
};

/*
 * Given a binary tree and a number ‘S’, find all paths in the tree such that
 * the sum of all the node values of each path equals ‘S’
 * Please note that the paths can start or end at any node
 * but all paths must follow direction from parent to child (top to bottom)
 */
int main() {
    Node *root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    root->left->left = new Node(4);
    root->right->left = new Node(10);
    root->right->right = new Node(5);

    cout << CountAllPathSumRecurse::countPaths(root, 11) << endl;

    cout << CountAllPathSumBacktrack::countPaths(root, 11) << endl;
}
