#include <bits/stdc++.h>

using namespace std;

int max_fruits_in_2basket(vector<char> fruits);

/*
 * Given an array of characters where each character represents a fruit tree,
 * you are given two baskets and your goal is to put maximum number of fruits in each basket.
 * The only restriction is that each basket can have only one type of fruit.
 *
 * You can start with any tree, but once you have started you can’t skip a tree.
 * You will pick one fruit from each tree until you cannot,
 * i.e., you will stop when you have to pick from a third fruit type.
 */
int main() {
    vector<char> fruits = {'A', 'B', 'C', 'A', 'C', 'A'};
    cout << max_fruits_in_2basket(fruits) << endl;
}

int max_fruits_in_2basket(vector<char> fruits) {
    int max_fruits = 0;
    int no_baskets = 2;
    unordered_map<char, int> fruit_freq_map;

    for (int window_start = 0, window_end = 0; window_end < fruits.size(); ++window_end) {
        ++fruit_freq_map[fruits[window_end]];

        while (fruit_freq_map.size() > no_baskets) {
            char left_char = fruits[window_start++];
            if (--fruit_freq_map[left_char] <= 0) {
                fruit_freq_map.erase(left_char);
            }
        }

        max_fruits = max(max_fruits, window_end - window_start + 1);
    }

    return max_fruits;
}
