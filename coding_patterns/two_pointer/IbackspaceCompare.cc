#include <bits/stdc++.h>

using namespace std;

bool backspaceCompare(string &str1, string &str2);

int nextValidIndex(string str, int index);

/*
 * Given two strings containing backspaces (identified by the character ‘#’),
 * check if the two strings are equal.
 */
int main() {
    string str1 = "xpy#b##", str2 = "##xyz##";
    cout << backspaceCompare(str1, str2);
}

bool backspaceCompare(string &str1, string &str2) {
    int i = (int) str1.size() - 1, j = (int) str2.size() - 1;

    while (i >= 0 || j >= 0) {
        int i1 = nextValidIndex(str1, i);
        int j1 = nextValidIndex(str2, j);

        if (i1 < 0 && j1 < 0)
            return true;

        if (i1 < 0 || j1 < 0 || str1[i1] != str2[j1])
            return false;

        i = i1 - 1;
        j = j1 - 1;
    }

    return true;
}

// returns next valid index [index, -1]
int nextValidIndex(string str, int index) {
    for (int backspaceCount = 0; index >= 0; --index)
        if (str[index] == '#')
            ++backspaceCount;
        else if (backspaceCount > 0)
            --backspaceCount;
        else
            break;

    return index;
}
