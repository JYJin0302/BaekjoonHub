#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll grid[1001][1001];
    ll mod = 1e9 + 9;
    grid[1][1] = 1;
    grid[2][1] = 1;
    grid[2][2] = 1;
    grid[3][1] = 1;
    grid[3][2] = 2;
    grid[3][3] = 1;
    for (int i = 4; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            grid[i][j] = (grid[i - 1][j - 1] + grid[i - 2][j - 1] + grid[i - 3][j - 1]) % mod;
        }
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            grid[i][j] = (grid[i][j] + grid[i][j-1])%mod;
        }
    }
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << grid[n][m] << '\n';
    }
}