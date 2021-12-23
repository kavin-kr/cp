#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=Y6T7l83eqQs
void testCase() {
    int k;
    cin >> k;

    vector<int> x, y;
    for (int i = 0; i < k; ++i) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x.push_back(x1);
        x.push_back(x2);
        y.push_back(y1);
        y.push_back(y2);
    }

    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());

    cout << x[k - 1] << " " << y[k - 1];
}

// https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3a1c
int32_t main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        testCase();
        cout << endl;
    }
}
