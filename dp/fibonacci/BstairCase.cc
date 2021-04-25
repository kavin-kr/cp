#include <bits/stdc++.h>

using namespace std;

struct BruteForce {
    static int solve(int n) {
        if (n <= 2)
            return n;

        return solve(n - 1) + solve(n - 2);
    }
};

struct Tabulation {
    static int solve(int n) {
        if(n <= 2)
            return n;

        int tmp, f1 = 1, f2 = 2;
        for(int i=3; i<=n; ++i) {
            tmp = f1 + f2;
            f1 = f2;
            f2 = tmp;
        }

        return f2;
    }
};

/*
 * https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
 */
int32_t main() {
    int n = 12;

    cout << "BruteForce: " << endl << BruteForce::solve(n) << "\n\n";
    cout << "Tabulation: " << endl << Tabulation::solve(n) << "\n\n";
}
