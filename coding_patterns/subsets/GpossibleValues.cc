#include <bits/stdc++.h>

using namespace std;

vector<int> possibleValues(string expr) {
    static unordered_map<string, vector<int>> cache;
    if (cache.find(expr) != cache.end())
        return cache[expr];

    int idx = expr.find_first_of("+-*");
    if (idx == string::npos && !expr.empty())
        return {stoi(expr)};

    vector<int> result;
    for (; idx != string::npos; idx = expr.find_first_of("+-*", idx + 1)) {
        vector<int> leftResult = possibleValues(expr.substr(0, idx));
        vector<int> rightResult = possibleValues(expr.substr(idx + 1));

        for (int x: leftResult)
            for (int y: rightResult)
                switch (expr[idx]) {
                    case '+': result.push_back(x + y); break;
                    case '-': result.push_back(x - y); break;
                    case '*': result.push_back(x * y); break;
                }
    }

    return cache[expr] = result;
}

/*
 * Given an expression containing digits and operations (+, -, *),
 * find all possible ways in which the expression can be evaluated
 * by grouping the numbers and operators using parentheses.
 */
int main() {
    auto result = possibleValues("3*1*2");
    for (auto &x: result)
        cout << x << " ";
    cout << endl;
}
