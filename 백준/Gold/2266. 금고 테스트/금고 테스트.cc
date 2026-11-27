#include <bits/stdc++.h>
using namespace std;

int n, k;
int grid[501][501];

void init() {
    for (int i = 1; i <= n; i++) {
        grid[i][1] = i;
    }
    for (int i = 1; i <= k; i++) {
        grid[1][i] = 1;
    }

    for (int r = 2; r <= n; r++) {
        for (int c = 2; c <= k; c++) {
            int temp = 501;
            for (int b = 2; b <= r; b++) {
                temp = min(temp, max(grid[b - 1][c - 1], grid[r - b][c]) + 1);
            }
            grid[r][c] = temp;
        }
    }

}

int main() {
    cin >> n >> k;

    init();
    cout << grid[n][k];

}