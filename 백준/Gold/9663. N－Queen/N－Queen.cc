#include <bits/stdc++.h>
using  namespace std;

int ans;
int grid[14][14];


bool safe(int n, int c, int size) {
    int tempn, tempc;
    tempn = n, tempc = c;
    while (tempn > 0 && tempc > 0) {
        tempn--; tempc--;
        if (grid[tempn][tempc]) return false;
    }
    tempn = n, tempc = c;
    while (tempn > 0 && tempc < size - 1) {
        tempn--, tempc++;
        if (grid[tempn][tempc]) return false;
    }
    tempn = n, tempc = c;
    while (tempn > 0) {
        tempn--;
        if (grid[tempn][tempc]) return false;
    }
    return true;
}


void solve(int n, int cnt) {
    if (cnt == n) {
        ans++; return;
    }

    for (int i = 0; i < n; i++) {
        if (!safe(cnt, i, n)) continue;
        grid[cnt][i] = 1;
        solve(n, cnt + 1);
        grid[cnt][i] = 0;
    }

}




int main() {
    int n;
    cin >> n;
    ans = 0;

    solve(n, 0);
    cout << ans;
}