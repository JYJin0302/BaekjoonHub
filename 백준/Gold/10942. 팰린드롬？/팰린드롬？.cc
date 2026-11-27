#include <bits/stdc++.h>
using namespace std;

int g[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, ti, tj, s, a, b;
    cin >> n;

    vector<int> base(n+1);
    for (int i = 1; i <= n; i++) cin >> base[i];

    for (int i = 1; i <= n; i++) g[i][i] = 1;

    s = 2;
    while (s <= n) {
        ti = 1;
        tj = s;
        while (tj <= n) {

            if (s == 2) {
                if (base[tj] == base[ti]) g[ti][tj] = 1;
            }
            else {
                if (g[ti + 1][tj - 1] && (base[tj] == base[ti])) g[ti][tj] = 1;
            }
            ti++, tj++;
        }
        s++;
    }

    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << g[a][b] << '\n';
    }
}