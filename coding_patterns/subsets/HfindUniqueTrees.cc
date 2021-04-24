#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left = nullptr, *right = nullptr;

    explicit Node(int val) : val(val) {}
};

class UniqueTrees {
    static vector<Node *> findUniqueTreesHelper(int start, int end) {
        if (start > end)
            return {nullptr};

        vector<Node *> result;

        for (int i = start; i <= end; ++i) {
            vector<Node *> leftTree = findUniqueTreesHelper(start, i - 1);
            vector<Node *> rightTree = findUniqueTreesHelper(i + 1, end);

            for (auto &x: leftTree)
                for (auto &y: rightTree) {
                    Node *node = new Node(i);
                    node->left = x;
                    node->right = y;
                    result.push_back(node);
                }
        }

        return result;
    }

public:
    static vector<Node *> findUniqueTrees(int num) {
        if (num <= 0)
            return {};

        return findUniqueTreesHelper(1, num);
    }
    // memoization not useful in this case as each tree in cache
    // has to be recreated again for returning from cache
};

class CountUniqueTrees {
public:
    static int countUniqueTrees(int num) {
        static unordered_map<int, unsigned long long> cache;
        if (cache.find(num) != cache.end())
            return cache[num];

        if (num <= 1)
            return 1;

        int result = 0;
        for (int i = 1; i <= num; ++i)
            result += countUniqueTrees(i - 1) * countUniqueTrees(num - i);

        return cache[num] = result;
    }
};

// number of binary search tree is equal to catalan number
// C(0) = 1
// C(n) = sum of C(i) * C(n-i-1) for n >= 0
unsigned long long catalanNumber(int num) {
    static unordered_map<int, unsigned long long> cache;
    if (cache.find(num) != cache.end())
        return cache[num];

    if (num <= 1)
        return 1;

    unsigned long long result = 0;
    for (int i = 0; i < num; ++i)
        result += catalanNumber(i) * catalanNumber(num - i - 1);

    return cache[num] = result;
}

/*
 * Given a number ‘n’, write a function to return all structurally unique
 * Binary Search Trees (BST) that can store values 1 to ‘n’
 */
int main() {
    int num = 1;
    cout << UniqueTrees::findUniqueTrees(num).size() << endl
         << CountUniqueTrees::countUniqueTrees(num) << endl
         << catalanNumber(num) << endl;
}
