#include <bits/stdc++.h>

using namespace std;

int longest_substring_no_repeat(string str);

/*
 * Given a string, find the length of the longest substring which has no repeating characters.
 */
int main() {
    string str = "aabccbb";
    cout << longest_substring_no_repeat(str) << endl;
}

int longest_substring_no_repeat(string str) {
    int max_len = 0;
    unordered_map<char, int> char_index_map;

    for (int window_start = 0, window_end = 0; window_end < str.size(); ++window_end) {
        char right_char = str[window_end];

        if (char_index_map.find(right_char) != char_index_map.end()) {
            window_start = max(window_start, char_index_map[right_char] + 1);
        }

        char_index_map[right_char] = window_end;
        max_len = max(max_len, window_end - window_start + 1);
    }

    return max_len;
}
