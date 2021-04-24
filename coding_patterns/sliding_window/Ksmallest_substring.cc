#include <bits/stdc++.h>

using namespace std;

string smallest_substring(string &str, string &pat);

/*
 * Given a string and a pattern,
 * find the smallest substring in the given string which has all the characters of the given pattern
 */
int main() {
    string str = "faabcde", pat = "abcef";
    cout << smallest_substring(str, pat) << endl;
}

string smallest_substring(string &str, string &pat) {
    int matched = 0, min_length = numeric_limits<int>::max(), str_s=0;
    unordered_map<char, int> freq;

    for (auto x: pat) ++freq[x];

    for (int ws = 0, we = 0; we < str.size(); ++we) {
        char rc = str[we];
        if (freq.find(rc) != freq.end() && --freq[rc] == 0) ++matched;
        while (matched == freq.size()) {
            if(min_length > we - ws + 1) {
                min_length = we - ws +1;
                str_s = ws;
            }
            char lc = str[ws++];
            if (freq.find(lc) != freq.end() && freq[lc]++ == 0) --matched;
        }
    }

    return min_length == numeric_limits<int>::max() ? "" : str.substr(str_s, min_length);
}
