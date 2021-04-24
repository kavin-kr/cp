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
    int profit, weight;

    Item(int profit, int weight) : profit{profit}, weight{weight} {}
};

ostream &operator<<(ostream &out, const Item &item) {
    out << "{W: " << item.weight << ", P: " << item.profit << "}";
    return out;
}

struct BruteForce {
    static int helper(int idx, int remCap, const vector<Item> &items) {
        if (idx >= items.size())
            return 0;

        int profit = helper(idx + 1, remCap, items);
        if (remCap >= items[idx].weight)
            profit = max(profit, items[idx].profit + helper(idx, remCap - items[idx].weight, items));

        return profit;
    }

    static int solve(const vector<Item> &items, int k) {
        return helper(0, k, items);
    }
};

struct Tabulation {
    static int solve(const vector<Item> &items, int k) {
        vector<vector<int>> dp(items.size() + 1, vector<int>(k + 1));
        for (int i = 0; i <= items.size(); ++i) {
            for (int j = 0; j <= k; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= items[i - 1].weight) {
                        dp[i][j] = max(dp[i][j], items[i - 1].profit + dp[i][j - items[i - 1].weight]);
                    }
                }
            }
        }

        cout << dp << endl;

        vector<Item> result;
        for (int i = items.size(), j = k; i > 0; --i) {
            while (dp[i][j] != dp[i - 1][j]) {
                result.push_back(items[i - 1]);
                j -= items[i - 1].weight;
            }
        }

        cout << result << endl;

        return dp[items.size()][k];
    }
};

struct Tabulation2 {
    static int solve(const vector<Item> &items, int k) {
        vector<int> dp(k + 1, 0);
        for (auto &item: items) {
            for (int j = 1; j <= k; ++j) {
                if (j >= item.weight)
                    dp[j] = max(dp[j], item.profit + dp[j - item.weight]);
            }
        }

        cout << dp << endl;

        return dp[k];
    }
};

struct Tabulation3 {
    static int solve(const vector<Item> &items, int k) {
        vector<int> dp(k + 1, 0);
        vector<int> used(k + 1);
        for (int i = 0; i < items.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                if (j >= items[i].weight) {
                    int newProfit = items[i].profit + dp[j - items[i].weight];
                    if (newProfit > dp[j]) {
                        dp[j] = newProfit;
                        used[j] = i;
                    }
                }
            }
        }

        cout << dp << endl;
        cout << used << endl;

        vector<Item> result;
        for (int j = k; j > 0; j -= items[used[j]].weight)
            result.push_back(items[used[j]]);

        cout << result << endl;

        return dp[k];
    }
};

/*
 * https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/
 */
int main() {
    vector<Item> items = {{15, 1},
                          {50, 3},
                          {60, 4},
                          {90, 5}};
    int capacity = 8;

    cout << "BruteForce: " << "\n" << BruteForce::solve(items, capacity) << "\n\n";
    cout << "Tabulation: " << "\n" << Tabulation::solve(items, capacity) << "\n\n";
    cout << "Tabulation2: " << "\n" << Tabulation2::solve(items, capacity) << "\n\n";
    cout << "Tabulation3: " << "\n" << Tabulation3::solve(items, capacity) << "\n\n";
}
