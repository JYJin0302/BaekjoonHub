#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, a, b, x, y;
    cin >> n >> m;

    vector<vector<int>> base(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> base[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            base[i][j] += base[i - 1][j] + base[i][j - 1] - base[i - 1][j - 1];
        }
    }

    while (m--) {
        cin >> a >> b >> x >> y;

        cout << base[x][y] - base[a - 1][y] - base[x][b - 1] + base[a - 1][b - 1] << '\n';
    }
}