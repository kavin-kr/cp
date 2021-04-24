#include <bits/stdc++.h>

using namespace std;

int longest_substring_with_k_distinct_chars(string str, int k);

/*
 * Given a string, 
 * find the length of the longest substring in it with no more than K distinct characters.
 */
int main() {
    string str = "google";
    int k = 2;

    cout << longest_substring_with_k_distinct_chars(str, k) << endl;
}

int longest_substring_with_k_distinct_chars(string str, int k) {
    int max_length = 0;
    unordered_map<char, int> char_freq_map;

    for(int window_start=0, window_end=0; window_start < str.size(); ++window_end) {
        ++char_freq_map[str[window_end]];

        while(char_freq_map.size() > k) {
            char left_char = str[window_start++];
            if(--char_freq_map[left_char] <= 0) {
                char_freq_map.erase(left_char);
            }
        }

        max_length = max(max_length, window_end - window_start + 1);
    }

    return max_length;
}
