#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left = nullptr, *right = nullptr;

    explicit Node(int val) : val(val) {}
};

class SumOfPathNumbers {
    static void findSumHelper(Node *currNode, int currSum, int &totalSum) {
        if (!currNode)
            return;

        if (!currNode->left && !currNode->right) {
            totalSum += (currSum * 10) + currNode->val;
        } else {
            findSumHelper(currNode->left, (currSum * 10) + currNode->val, totalSum);
            findSumHelper(currNode->right, (currSum * 10) + currNode->val, totalSum);
        }
    }

public:
    static int findSum(Node *root) {
        int totalSum = 0;
        findSumHelper(root, 0, totalSum);
        return totalSum;
    }
};

/*
 * Given a binary tree where each node can only have a digit (0-9) value,
 * each root-to-leaf path will represent a number.
 * Find the total sum of all the numbers represented by all paths.
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(2);
    root->right->right->right = new Node(1);

    cout << SumOfPathNumbers::findSum(root) << endl;
}