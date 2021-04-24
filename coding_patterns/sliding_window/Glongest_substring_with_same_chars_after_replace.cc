#include <bits/stdc++.h>

using namespace std;

int longest_substring_with_same_chars_after_replace(string str, int k);

/*
 * Given a string with lowercase letters only,
 * if you are allowed to replace no more than ‘k’ letters with any letter,
 * find the length of the longest substring having the same letters after replacement
 */
int main() {
    string str = "aabbccbb";
    int k = 2;

    cout << longest_substring_with_same_chars_after_replace(str, k) << endl;
}

int longest_substring_with_same_chars_after_replace(string str, int k) {
    int max_len = 0, max_repeat_count = 0;
    unordered_map<char, int> char_freq_map;

    // extend the window only if possible
    // and keep its size even if has different chars
    for (int window_start = 0, window_end = 0; window_end < str.size(); ++window_end) {
        char right_char = str[window_end];
        ++char_freq_map[right_char];
        max_repeat_count = max(max_repeat_count, char_freq_map[right_char]);

        if (window_end - window_start + 1 - max_repeat_count > k) {
            --char_freq_map[str[window_start++]];
        }

        max_len = max(max_len, window_end - window_start + 1);
    }

    return max_len;
}
