#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

bool conn[101][101];
int p[101];

void solve() {

    int n;
    cin >> n;

    int cur = 1;
    int cnt = 0;

    while (cnt < n - 1) {
        cout << "maze" << endl;
        int v;
        cin >> v;
        if (conn[cur][v] || conn[v][cur]) {
            // go to parent
            if (v == p[cur]) {}
            else {
                cout << "gaji " << cur << endl;
                cin >> v;
                cout << "gaji " << p[cur] << endl;
                cin >> v;
            }
            cur = p[cur];
        }
        else {
            p[v] = cur;
            conn[cur][v] = 1;
            conn[v][cur] = 1;
            cur = v;
            cnt++;
        }
    }

    cout << "answer" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (conn[i][j] || conn[j][i]) cout << i << ' ' << j << endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}