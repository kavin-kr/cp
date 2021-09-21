#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
  #include "pprint.hpp"
  #define dbg(x) cout << #x << " := "; pprint::PrettyPrinter(false).print(x)
#else
  #define dbg(x) 5
#endif

void testCase() {
    int n;
    string str;
    cin >> n >> str;

    vector<int> leftDist(n), rightDist(n);
    for (int i = 0, closest = 1E9; i < n; ++i) {
        if(str[i] == '1')
            closest = i;
        leftDist[i] = closest;
    }
    for (int i = n-1, closest = 1E9; i>=0; --i) {
        if(str[i] == '1')
            closest = i;
        rightDist[i] = closest;
    }

    long long ans = 0;
    for(int i=0; i<n; ++i)
        ans += min(abs(i - leftDist[i]), abs(rightDist[i]-i));

    cout << ans;
}

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000887c32
int32_t main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        testCase();
        cout << endl;
    }
}
