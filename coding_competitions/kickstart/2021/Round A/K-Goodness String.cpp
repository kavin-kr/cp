#include <bits/stdc++.h>

using namespace std;

void testCase() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int currScore = 0;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (s[i] != s[j])
            ++currScore;
    }

    cout << abs(k - currScore);
}

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cca3
int32_t main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        testCase();
        cout << endl;
    }
}
