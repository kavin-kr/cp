#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void testCase() {
    ll n, d, c, m;
    cin >> n >> d >> c >> m;

    vector<char> str(n);
    for (char &ch: str)
        cin >> ch;

    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'D') {
            if (--d < 0 || flag) {
                cout << "NO";
                return;
            }
            c += m;
        } else {
            if (--c < 0) {
                flag = true;
            }
        }
    }

    cout << "YES";
}

// https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3771
int32_t main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        testCase();
        cout << endl;
    }
}
