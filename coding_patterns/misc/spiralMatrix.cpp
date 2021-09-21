#include <iostream>

using namespace std;
#define N 4
#define M 4

void printMatrixSpirally(int rows, int cols, int arr[N][M]) {
    enum Direction {
        LEFT_TO_RIGHT = 0, TOP_TO_BOTTOM, RIGHT_TO_LEFT, BOTTOM_TO_TOP
    };

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    for (int dir = 0; top <= bottom && left <= right; dir = (dir + 1) % 4) {
        if (dir == LEFT_TO_RIGHT) {
            for (int i = left; i <= right; ++i) {
                cout << arr[top][i] << " ";
            }
            ++top;
        } else if (dir == TOP_TO_BOTTOM) {
            for (int i = top; i <= bottom; ++i) {
                cout << arr[i][right] << " ";
            }
            --right;
        } else if (dir == RIGHT_TO_LEFT) {
            for (int i = right; i >= left; --i) {
                cout << arr[bottom][i] << " ";
            }
            --bottom;
        } else if (dir == BOTTOM_TO_TOP) {
            for (int i = bottom; i >= top; --i) {
                cout << arr[i][left] << " ";
            }
            ++left;
        }
    }
}

int main() {
    int mat[N][M] = {{1,  2,  3,  4},
                     {12, 13, 14, 5},
                     {11, 16, 15, 6},
                     {10, 9,  8,  7}};

    printMatrixSpirally(N, M, mat);
}