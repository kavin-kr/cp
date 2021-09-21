#include <bits/stdc++.h>

using namespace std;

vector<int> naivePatternSearch(const string &s, const string &p) {
    vector<int> result;

    const int sSize = s.size(), pSize = p.size();

    for (int i = 0, j; i <= (sSize - pSize); ++i) {
        for (j = 0; j < pSize; ++j)
            if (s[i + j] != p[j]) {
                break;
            }

        if (j == pSize)
            result.push_back(i);
    }

    return result;
}

// https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/
int32_t main() {
    const string s = "ABAAABCDBBABCDDEBCABC", p = "ABC";
    
    vector<int> matches = naivePatternSearch(s, p);
    for (int idx: matches)
        cout << idx << endl;
}
