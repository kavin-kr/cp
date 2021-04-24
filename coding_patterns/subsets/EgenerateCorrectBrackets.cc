#include <bits/stdc++.h>

using namespace std;

vector<string> generateCorrectBrackets(int pairCount) {
    if (pairCount <= 0) {
        return {};
    }

    struct BString {
        int opened, closed;
        string str;

        BString(string str, int opened, int closed) : str(std::move(str)), opened(opened), closed(closed) {}
    };
    queue<BString> queue;
    queue.emplace("(", 1, 0);

    vector<string> result;
    while (!queue.empty()) {
        for (int qi = 0, qSize = queue.size(); qi < qSize; ++qi) {
            BString tmp = queue.front();
            queue.pop();

            if (tmp.opened < pairCount)
                queue.emplace(tmp.str + "(", 1 + tmp.opened, tmp.closed);

            if (tmp.closed < tmp.opened) {
                if (tmp.closed + 1 == pairCount)
                    result.push_back(tmp.str + ")");
                else
                    queue.emplace(tmp.str + ")", tmp.opened, 1 + tmp.closed);
            }
        }
    }

    return result;
};

/*
 * For a given number ‘N’, write a function to generate all combination of ‘N’ pairs of balanced parentheses.
 */
int main() {
    for (auto &x: generateCorrectBrackets(2))
        cout << x << endl;
}
