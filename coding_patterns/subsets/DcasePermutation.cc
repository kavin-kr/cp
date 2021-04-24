#include <bits/stdc++.h>

using namespace std;

vector<string> casePermutation(const string &str) {
    vector<string> result({str});

    for (int si = 0, sSize = str.size(); si < sSize; ++si) {
        if (!isalpha(str[si]))
            continue;

        for (int ri = 0, rSize = result.size(); ri < rSize; ++ri) {
            string newPerm(result[ri]);
            // newPerm[si] ^= 32; // toggle case
            newPerm[si] = isupper(str[si]) ? tolower(newPerm[si]) : toupper(newPerm[si]);
            result.emplace_back(newPerm);
        }
    }

    return result;
}

/*
 * Given a string, find all of its permutations preserving the character sequence but changing case.
 */
int main() {
    auto result = casePermutation("ab7c");
    for (auto &x: result)
        cout << x << endl;
}
