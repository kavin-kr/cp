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
    string name;

    Item(int profit, int weight, string name = "") : profit{profit}, weight{weight}, name{std::move(name)} {}
};

class BruteForce {
    static int solve(int currIdx, int remCapacity, const vector<Item> &items) {
        if (currIdx >= items.size() || remCapacity <= 0)
            return 0;

        int maxProfit = solve(currIdx + 1, remCapacity, items);
        if (remCapacity >= items[currIdx].weight)
            maxProfit = max(maxProfit,
                            items[currIdx].profit + solve(currIdx + 1, remCapacity - items[currIdx].weight, items));

        return maxProfit;
    }

public:
    static int solve(const vector<Item> &items, const int capacity) {
        return solve(0, capacity, items);
    }
};

class Memoization {
    static int solve(int currIdx, int remCapacity, vector<vector<int>> &memo, const vector<Item> &items) {
        if (currIdx >= items.size() || remCapacity <= 0)
            return 0;

        if (memo[currIdx][remCapacity] != -1)
            return memo[currIdx][remCapacity];

        int maxProfit = solve(currIdx + 1, remCapacity, memo, items);
        if (remCapacity >= items[currIdx].weight)
            maxProfit = max(maxProfit,
                            items[currIdx].profit +
                            solve(currIdx + 1, remCapacity - items[currIdx].weight, memo, items));

        return memo[currIdx][remCapacity] = maxProfit;
    }

public:
    static int solve(const vector<Item> &items, const int capacity) {
        vector<vector<int>> memo(items.size(), vector<int>(capacity + 1, -1));
        int result = solve(0, capacity, memo, items);
        cout << memo << endl;
        return result;
    }
};

class Tabulation {
public:
    static int solve(const vector<Item> &items, const int capacity) {
        vector<vector<int>> dp(items.size() + 1, vector<int>(capacity + 1));

        for (int i = 0; i <= items.size(); ++i)
            for (int j = 0; j <= capacity; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= items[i - 1].weight)
                        dp[i][j] = max(dp[i][j], items[i - 1].profit + dp[i - 1][j - items[i - 1].weight]);
                }
            }

        vector<int> included;
        for (int i = items.size(), j = capacity; i > 0 && j > 0; --i)
            if (dp[i][j] != dp[i - 1][j]) {
                included.emplace_back(i);
                j -= items[i - 1].weight;
            }

        cout << dp << endl;
        cout << included << endl;

        return dp[items.size()][capacity];
    }
};

class Tabulation2 {
public:
    static int solve(const vector<Item> &items, const int capacity) {
        vector<int> dp(capacity + 1, 0);

        for (const auto &item : items)
            for (int j = capacity; j > 0; --j) {
                if (j >= item.weight)
                    dp[j] = max(dp[j], item.profit + dp[j - item.weight]);
            }

        cout << dp << endl;

        return dp[capacity];
    }
};

/*
 * https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
 */
int main() {
    vector<Item> items = {{4, 2},
                          {7, 3},
                          {3, 1},
                          {5, 4}};
    int capacity = 5;

    cout << "BruteForce: " << endl << BruteForce::solve(items, capacity) << "\n\n";
    cout << "Memoization: " << endl << Memoization::solve(items, capacity) << "\n\n";
    cout << "Tabulation: " << endl << Tabulation::solve(items, capacity) << "\n\n";
    cout << "Tabulation2: " << endl << Tabulation2::solve(items, capacity) << "\n\n";
}
