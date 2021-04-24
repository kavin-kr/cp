#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
    out << "[";
    for (int i = 0, size = arr.size(); i < size; ++i)
        out << setw(2) << arr[i] << (i + 1 == size ? "" : ", ");
    out << "]";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<vector<T>> &mat) {
    out << "[";
    for (int i = 0, size = mat.size(); i < size; ++i)
        out << mat[i] << (i + 1 == size ? "" : ", \n ");
    out << "]";
    return out;
}

struct Item {
    int price, length;

    Item(int length, int price) : price{price}, length{length} {}
};

ostream &operator<<(ostream &out, const Item &item) {
    out << "{L: " << item.length << ", P: " << item.price << "}";
    return out;
}

struct BruteForce {
    static int helper(int idx, int remCapacity, const vector<Item> &items) {
        if (idx >= items.size())
            return 0;

        int res = helper(idx + 1, remCapacity, items);
        if (remCapacity >= items[idx].length)
            res = max(res, items[idx].price + helper(idx, remCapacity - items[idx].length, items));

        return res;
    }

    static int solve(const vector<Item> &items, int capacity) {
        return helper(0, capacity, items);
    }
};

struct Tabulation {
    static int solve(const vector<Item> &items, const int capacity) {
        vector<vector<int>> dp(items.size() + 1, vector<int>(capacity + 1));

        for (int i = 0; i <= items.size(); ++i) {
            for (int j = 0; j <= capacity; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= items[i - 1].length)
                        dp[i][j] = max(dp[i][j], items[i - 1].price + dp[i][j - items[i - 1].length]);
                }
            }
        }

        cout << dp << endl;

        vector<Item> result;
        for (int i = items.size(), j = capacity; i > 0; --i) {
            while (dp[i][j] != dp[i - 1][j]) {
                result.push_back(items[i - 1]);
                j -= items[i - 1].length;
            }
        }

        cout << result << endl;

        return dp[items.size()][capacity];
    }
};

struct Tabulation2 {
    static int solve(const vector<Item> &items, int capacity) {
        vector<int> dp(capacity + 1, 0), used(capacity + 1);

        for (int i = 0; i < items.size(); ++i) {
            for (int j = 0; j <= capacity; ++j) {
                if (j >= items[i].length && dp[j - items[i].length] + items[i].price > dp[j]) {
                    dp[j] = dp[j - items[i].length] + items[i].price;
                    used[j] = i;
                }
            }
        }

        cout << dp << endl;
        cout << used << endl;

        vector<Item> result;
        for (int j = capacity; j > 0; j -= items[used[j]].length)
            result.push_back(items[used[j]]);

        cout << result << endl;

        return dp[capacity];
    }
};

/*
 * https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
 */
int main() {
    vector<Item> items = {{1, 1},
                          {2, 5},
                          {3, 8},
                          {4, 9},
                          {5, 10},
                          {6, 16},
                          {7, 17},
                          {8, 20}};
    int capacity = 8;

    cout << "BruteForce: " << "\n" << BruteForce::solve(items, capacity) << "\n\n";
    cout << "Tabulation: " << "\n" << Tabulation::solve(items, capacity) << "\n\n";
    cout << "Tabulation2: " << "\n" << Tabulation2::solve(items, capacity) << "\n\n";
}
