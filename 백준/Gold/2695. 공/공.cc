#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int grid[1001][51];

void init() {
    for (int i = 1; i <= 1000; i++) {
        grid[i][1] = i;
    }
    for (int i = 1; i <= 50; i++) {
        grid[1][i] = 1;
    }

    for (int r = 2; r <= 1000; r++) {
        for (int c = 2; c <= 50; c++) {
            int temp = 501;
            for (int b = 2; b <= r; b++) {
                temp = min(temp, max(grid[b - 1][c - 1], grid[r - b][c]) + 1);
            }
            grid[r][c] = temp;
        }
    }

}

int main() {
    cin >> t;

    init();
    while (t--) {
        cin >> n >> k;
        cout << grid[k][n] << '\n';
    }

}