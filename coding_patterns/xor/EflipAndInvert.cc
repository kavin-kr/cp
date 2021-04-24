#include <bits/stdc++.h>

using namespace std;

void flipAndInvert(vector<vector<int>> &image) {
    int n = image[0].size();
    for (auto &r : image)
        for (int c = 0; c < (n + 1) / 2; ++c) {
            int tmp = r[c] ^ 1;
            r[c] = r[n - 1 - c] ^ 1;
            r[n - 1 - c] = tmp;
        }
}

/*
 * Given a binary matrix representing an image, we want to flip the image horizontally, then invert it.
 * To flip an image horizontally means that each row of the image is reversed.
 * For example, flipping [0, 1, 1] horizontally results in [1, 1, 0].
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
 * For example, inverting [1, 1, 0] results in [0, 0, 1]
 */
int main() {
    vector<vector<int>> image = {{1, 0, 1},
                                 {1, 1, 1},
                                 {0, 1, 1}};

    flipAndInvert(image);
    for (auto &x: image) {
        for (auto &y: x)
            cout << y << " ";
        cout << endl;
    }
}
