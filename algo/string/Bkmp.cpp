#include <bits/stdc++.h>

using namespace std;

vector<int> prefixFunction(const string &str) {
    auto n = str.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j])
            j = pi[j - 1];
        if (str[i] == str[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(const string &str, const string &pat) {
    vector<int> result;

    const auto sSize = str.size(), pSize = pat.size();
    vector<int> lps = prefixFunction(pat);
    for (int i = 0, j = 0; i < sSize;) {
        if (str[i] == pat[j]) {
            ++i;
            ++j;
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                ++i;
        }

        if (j == pSize) {
            result.push_back(i - j);
            j = lps[j - 1];
        }
    }

    return result;
}

// https://www.youtube.com/watch?v=4jY57Ehc14Y
// https://cp-algorithms.com/string/prefix-function.html
int32_t main() {
    const string s = "onionionionion", p = "onion";

    vector<int> matches = kmp(s, p);
    for (int idx: matches)
        cout << idx << endl;
}
