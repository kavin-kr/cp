#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left = nullptr, *right = nullptr;

    explicit Node(int val) : val(val) {}
};

class PathWithGivenSequence {
    static bool hasSequenceHelper(Node *curr, int idx, vector<int> &seq) {
        if (!curr || idx >= seq.size())
            return false;

        if (curr->val == seq[idx]) {
            if (idx == seq.size() - 1 && (!curr->left && !curr->right))
                return true;
            else
                return hasSequenceHelper(curr->left, idx + 1, seq)
                       || hasSequenceHelper(curr->right, idx + 1, seq);
        }

        return false;
    }

public:
    static bool hasSequence(Node *root, vector<int> seq) {
        return hasSequenceHelper(root, 0, seq);
    }
};

/*
 * Given a binary tree and a number sequence, find if the sequence is present
 * as a root-to-leaf path in the given tree
 */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(2);
    root->right->right->right = new Node(1);

    cout << boolalpha << PathWithGivenSequence::hasSequence(root, {1, 2, 5});
}
