#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

bool A[5][5];
pair<int, int> pos[26];

void solve() {
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            pos[x] = mp(i, j);
        }
    }

    int ans = 0, cnt = 0;
    for (int i = 0; i < 25; i++) {
        int x;
        cin >> x;
        ans++;

        int a, b;
        tie(a, b) = pos[x];
        A[a][b] = 1;

        // row
        bool ok = 1;
        for (int j = 0; j < 5; j++) {
            ok &= A[a][j];
        }
        if (ok) cnt++;

        // col
        ok = 1;
        for (int j = 0; j < 5; j++) {
            ok &= A[j][b];
        }
        if (ok) cnt++;

        // diag
        if (a == b) {
            ok = 1;
            for (int j = 0; j < 5; j++) {
                ok &= A[j][j];
            }
            if (ok) cnt++;
        }

        if (a + b == 4) {
            ok = 1;
            for (int j = 0; j < 5; j++) {
                ok &= A[j][4-j];
            }
            if (ok) cnt++;
        }

        if (cnt >= 3) break;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}