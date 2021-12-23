#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    cout << "1 ";
    for (int i = 1, lastValue = 1; i < s.length(); ++i) {
        lastValue = (s[i - 1] < s[i]) ? lastValue + 1 : 1;
        cout << lastValue << " ";
    }
}

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a882
int32_t main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
        cout << endl;
    }
}
