#include <bits/stdc++.h>
using namespace std;

#define int long long

constexpr int MAX_VAL = 1E9 + 10;
bitset <MAX_VAL> isComposite;
vector<int> primes;

// https://codeforces.com/blog/entry/54090
void initPrimes() {
    for (int i = 2; i < MAX_VAL; ++i) {
        if (!isComposite[i])
            primes.push_back(i);

        for (int j = 0; j < primes.size() && i * primes[j] < MAX_VAL; j++) {
            isComposite[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    int z;
    cin >> z;

    int ans = 0;
    for (int left = 0, right = primes.size() - 2, mid, tmp; left <= right;) {
        mid = left + (right - left) / 2;
        tmp = primes[mid] * primes[mid + 1];
        if (tmp <= z) {
            ans = tmp;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans;
}

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a8e6#problem
int32_t main() {
    initPrimes();

    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
        cout << endl;
    }
}
