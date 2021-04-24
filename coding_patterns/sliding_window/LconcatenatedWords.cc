#include <bits/stdc++.h>

using namespace std;

vector<int> concatenated_words(string &str, vector<string> &words);

/*
 * Given a string and a list of words,
 * find all the starting indices of substrings in the given string
 * that are a concatenation of all the given words exactly once without any overlapping of words.
 * It is given that all words are of the same length.
 */
int main() {
    string str = "catfoxcat";
    vector<string> words = {"cat", "fox"};

    for (auto x: concatenated_words(str, words)) cout << x << " ";
    cout << endl;
}

vector<int> concatenated_words(string &str, vector<string> &words) {
    unordered_map<string, int> freq;
    for (auto &x: words) ++freq[x];

    vector<int> result;
    int wc = words.size(), wl = words[0].length();

    for (int i = 0; i <= str.length() - wc * wl; ++i) {
        unordered_map<string, int> words_seen;
        for (int j = 0; j < wc; ++j) {
            int next_word_index = i + j * wl;
            string word = str.substr(next_word_index, wl);

            if (freq.find(word) == freq.end()) break;

            ++words_seen[word];

            if (words_seen[word] > freq[word]) break;

            if (j + 1 == wc) result.push_back(i);
        }
    }

    return result;
}
