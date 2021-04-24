#include <bits/stdc++.h>

using namespace std;

vector<int> anagrams(string &str, string &pattern);

/*
 * Given a string and a pattern, find all anagrams of the pattern in the given string
 */
int main() {
    string str = "abbcab", pattern = "abc";
    vector<int> result = anagrams(str, pattern);

    for (auto x: result) {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> anagrams(string &str, string &pattern) {
    vector<int> result;

    int matched = 0;
    unordered_map<char, int> freq;
    for (auto x: pattern) {
        ++freq[x];
    }

    for (int ws = 0, we = 0; we < str.size(); ++we) {
        char rc = str[we];
        if (freq.find(rc) != freq.end() && --freq[rc] == 0) ++matched;
        if (matched == freq.size()) result.emplace_back(ws);
        if (we >= pattern.size() - 1) {
            char lc = str[ws++];
            if (freq.find(lc) != freq.end() && freq[lc]++ == 0) --matched;
        }
    }

    return result;
}
