#include <bits/stdc++.h>

using namespace std;

struct SortedPair {
    int x, y;

    SortedPair(int x, int y) {
        if (x > y)
            swap(x, y);

        this->x = x;
        this->y = y;
    }

    bool operator==(const SortedPair &other) const {
        return x == other.x && y == other.y;
    }

    struct HashFunction {
        size_t operator()(const SortedPair &sortedPair) const {
            constexpr size_t GOLDEN_RATIO = 0x9E3779B9;
            size_t seed = 0;
            seed ^= hash<int>()(sortedPair.x) + GOLDEN_RATIO + (seed << 6) + (seed >> 2);
            seed ^= hash<int>()(sortedPair.y) + GOLDEN_RATIO + (seed << 6) + (seed >> 2);
            return seed;
        }
    };
};

/*
 * --- GOLDEN RATIO CONSTANTS ---
 * https://github.com/HowardHinnant/hash_append/issues/7#issuecomment-371758166
 *
 * 8-bit    : 158 or 0x9E.
 * 16 bit   : 40 503 or 0x9E37.
 * 32-bit   : 2 654 435 769 or 0x9E3779B9.
 * 64-bit   : 11 400 714 819 323 198 485 or0x9E3779B97F4A7C15.
 * 128-bit  : 210 306 068 529 402 873 165 736 369 884 017 287 508 or 0x9E3779B97F4A7C15F39CC0605D396154.
 *
 * --- FOR GENERIC FUNCTION TEMPLATES ---
 * https://youngforest.github.io/2020/05/27/best-implement-to-use-pair-as-key-to-std-unordered-map-in-C/
 */
int main() {
    unordered_map<SortedPair, int, SortedPair::HashFunction> memo;

    memo[{3, 4}] = 9;
    memo[{4, 3}] = 0;

    for (auto &p: memo)
        cout << p.first.x << ", " << p.first.y << " -> " << p.second << endl;

    cout << SortedPair::HashFunction()({3, 4}) << endl;
    cout << SortedPair::HashFunction()({4, 3}) << endl;
}
