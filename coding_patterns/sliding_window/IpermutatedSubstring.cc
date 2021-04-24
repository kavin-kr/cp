#include <bits/stdc++.h>

using namespace std;

bool is_permutated_substring(string &str, string &pattern);

/*
 * Given a string and a pattern,
 * find out if the string contains any permutation of the pattern.
 */
int main() {
    string str = "aaacb", pattern = "abc";
    cout << is_permutated_substring(str, pattern) << endl;
}

bool is_permutated_substring(string &str, string &pattern) {
    int matched = 0;
    unordered_map<char, int> char_freq_map;
    for (auto x: pattern) {
        ++char_freq_map[x];
    }

    for (int window_start = 0, window_end = 0; window_end < str.size(); ++window_end) {
        char right_char = str[window_end];

        if (char_freq_map.find(right_char) != char_freq_map.end()
                && --char_freq_map[right_char] == 0)
            ++matched;

        if (matched == char_freq_map.size()) return true;

        if (window_end >= pattern.size() - 1) {
            char left_char = str[window_start++];

            if (char_freq_map.find(left_char) != char_freq_map.end()
                    && char_freq_map[left_char]++ == 0)
                --matched;
        }
    }

    return false;
}
