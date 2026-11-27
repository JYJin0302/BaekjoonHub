#include <bits/stdc++.h>
using namespace std;

int n, l;
int grid[100][100];



int main() {

    cin >> n >> l;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
    }

    int cnt = 0;
    // check row
    for (int i = 0; i < n; i++) {
        int len = 0;
        int need = 0;
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (j == 0 || grid[i][j - 1] == grid[i][j]) {
                if (need == 0) len++;
                need = max(0, need - 1);
                continue;
            }
            if (need > 0) { ok = false; break; }

            if (abs(grid[i][j - 1] - grid[i][j]) >= 2) { ok = false; break; }

            if (grid[i][j - 1] < grid[i][j]) {
                if (len < l || need > 0) { ok = false; break; }
                len = 1;
            }
            else {
                need = l-1;
                len = 0;
            }
        }
        if (need > 0) ok = false;
        if (ok) cnt++;
    }

    //check col
    for (int i = 0; i < n; i++) {
        int len = 0;
        int need = 0;
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (j == 0 || grid[j - 1][i] == grid[j][i]) {
                if (need == 0) len++;
                need = max(0, need - 1);
                continue;
            }
            if (need > 0) { ok = false; break; }
            
            if (abs(grid[j - 1][i] - grid[j][i]) >= 2) { ok = false; break; }

            if (grid[j - 1][i] < grid[j][i]) {
                if (len < l) { ok = false; break; }
                len = 1;
            }
            else {
                need = l-1;
                len = 0;
            }
        }
        if (need > 0) ok = false;
        if (ok) cnt++;
    }

    cout << cnt;
}