#include <bits/stdc++.h>

using namespace std;

template<
        template<typename...> class C,
        typename... Args
>
void print(C<Args...> container) {
    cout << "[";
    for (auto it = container.cbegin(); it != container.cend();)
        cout << *it << (++it != container.cend() ? ", " : "");
    cout << "]\n";
}

struct BruteForce {
    static int solve(const vector<int> &arr) {
        function<int(int)> lisEndingAtIdx = [&](int idx) {
            int ans = 1;
            for (int i = idx - 1; i >= 0; --i)
                if (arr[i] < arr[idx]) {
                    ans = max(ans, 1 + lisEndingAtIdx(i));
                }
            return ans;
        };

        function<int(int)> ldsStartingAtIdx = [&](int idx) {
            int ans = 1;
            for (int i = idx + 1; i < arr.size(); ++i)
                if (arr[i] < arr[idx]) {
                    ans = max(ans, 1 + ldsStartingAtIdx(i));
                }
            return ans;
        };

        int maxLen = 0;
        for (int i = 0; i < arr.size(); ++i)
            maxLen = max(maxLen, lisEndingAtIdx(i) + ldsStartingAtIdx(i) - 1);
        return maxLen;
    }
};

struct Tabulation {
    static int solve(const vector<int> &arr) {
        vector<int> lis(arr.size(), 1), lds(arr.size(), 1);

        for (int i = 1; i < arr.size(); ++i)
            for (int j = i - 1; j >= 0; --j)
                if (arr[j] < arr[i]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }

        for (int i = arr.size() - 2; i >= 0; --i)
            for (int j = i + 1; j < arr.size(); ++j)
                if (arr[i] > arr[j]) {
                    lds[i] = max(lds[i], 1 + lds[j]);
                }

        int maxLen = 0;
        for (int i = 0; i < arr.size(); ++i)
            maxLen = max(maxLen, lis[i] + lds[i] - 1);

        print(lis);
        print(lds);

        return maxLen;
    }
};

struct Tabulation2 {
    static int solve(const vector<int> &arr) {
        vector<int> lis(arr.size(), 1), lds(arr.size(), 1);

        for (int i = 1; i < arr.size(); ++i)
            for (int j = i - 1; j >= 0; --j)
                if (arr[j] < arr[i]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }

        for (int i = arr.size() - 2; i >= 0; --i)
            for (int j = i + 1; j < arr.size(); ++j)
                if (arr[i] > arr[j]) {
                    lds[i] = max(lds[i], 1 + lds[j]);
                }


        int maxIdx = -1;
        for (int i = 0; i < arr.size(); ++i)
            if (maxIdx == -1 || lis[maxIdx] + lds[maxIdx] - 1 < lis[i] + lds[i] - 1) {
                maxIdx = i;
            }

        if (maxIdx == -1)
            return 0;

        list<int> lbs;
        for (int i = maxIdx; lis[i] > 1;)
            for (int j = i - 1; j >= 0; --j)
                if (lis[j] + 1 == lis[i]) {
                    lbs.push_front(arr[j]);
                    i = j;
                    break;
                }
        lbs.push_back(arr[maxIdx]);
        for (int i = maxIdx; lds[i] > 1;)
            for (int j = i + 1; i <= arr.size() - 1; ++j)
                if (lds[j] + 1 == lds[i]) {
                    lbs.push_back(arr[j]);
                    i = j;
                    break;
                }
        print(lbs);

        return lis[maxIdx] + lds[maxIdx] - 1;
    }
};

// https://iq.opengenus.org/longest-bitonic-sequence/
// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
int32_t main() {
    vector<int> arr = {4, 2, 5, 9, 7, 6, 10, 3, 1, -2};

    cout << "BruteForce: \n" << BruteForce::solve(arr) << endl;
    cout << "Tabulation: \n" << Tabulation::solve(arr) << endl;
    cout << "Tabulation2: \n" << Tabulation2::solve(arr) << endl;
}

/*
// BruteForce based on prev index value
int lbs(int idx, int pre, bool isMin)
{
    if(idx == n)
        return 0;
    
    int count = lbs(idx+1, pre, isMin);

    if(isMin and arr[idx] > pre)
        count = max(count, 1+lbs(idx+1, arr[idx], true));
    else if(isMin and arr[idx] < pre)
        count = max(count, 1+lbs(idx+1, arr[idx], false));
    else if(!isMin and arr[idx] < pre)
        count = max(count, 1+lbs(idx+1, arr[idx], false));

    return count;
}
*/