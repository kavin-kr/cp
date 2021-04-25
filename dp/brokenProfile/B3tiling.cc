#include <bits/stdc++.h>

using namespace std;

struct RecursiveApproach {
    // one box un-filled
    static int h(int n) {
        if (n <= 0) return 0;
        if (n == 3) return 1;

        return f(n - 2) + h(n - 3);
    }

    // two box un-filled
    static int g(int n) {
        if (n <= 3) return 0;

        return h(n - 1) + g(n - 3);
    }

    // full boxes un-filled
    static int f(int n) {
        if (n <= 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (n == 3) return 2;

        return f(n - 1) + f(n - 3) + (2 * g(n - 2));
    }

    static int solve(int n) {
        return f(n);
    }
};

constexpr int MOD = 1E9 + 7;
constexpr int MAX_VAL = 1E6+10;

int dp_2[MAX_VAL];
int dp_3[MAX_VAL][4];

int testCase() {
    int k, n;
    cin >> k >> n;

    if (n <= 0)
        return n;

    if (k == 1) {
        return n % 3 == 0 ? 1 : 0;
    } else if (k == 2) {
        memset(dp_2, 0, sizeof(dp_2));
        dp_2[1] = 0;
        dp_2[2] = dp_2[3] = 1;

        for (int i = 4; i <= n; ++i) {
            dp_2[i] = (dp_2[i - 2] + dp_2[i - 3]) % MOD;
        }

        return dp_2[n];
    } else {
        memset(dp_3, 0, sizeof(dp_3));

        // i : no of columns
        // j : state of blocks
        //   1 - three unfilled boxes
        //   2 - two unfilled boxes
        //   3 - one unfilled boxes

        // Refer this for alternative base case where dp_3[0][3] = 1
        // https://www.youtube.com/watch?v=aWbxqYjaQM0
        
        dp_3[1][1] = 1;
        dp_3[1][2] = 0;
        dp_3[1][3] = 0;

        dp_3[2][1] = 1;
        dp_3[2][2] = 0;
        dp_3[2][3] = 0;

        dp_3[3][1] = 2;
        dp_3[3][2] = 0;
        dp_3[3][3] = 1;

        for (int i = 4; i <= n; ++i) {
            dp_3[i][1] = (((dp_3[i - 1][1] + dp_3[i - 3][1]) % MOD) + ((2 * dp_3[i - 2][2]) % MOD)) % MOD;
            dp_3[i][2] = (dp_3[i - 1][3] + dp_3[i - 3][2]) % MOD;
            dp_3[i][3] = (dp_3[i - 2][1] + dp_3[i - 3][3]) % MOD;
        }

        return dp_3[n][1];
    }
}

/*
 * Question: https://www.codechef.com/INOIPRAC/problems/INOI2002
 * Tutorial: https://www.youtube.com/watch?v=8IQgU95iZ58
 * Solution: https://ideone.com/wSuyz6
 */
int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 0; tc < tcs; ++tc)
        cout << testCase() << endl;
}
