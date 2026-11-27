#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


int A[101][101];

void solve() {

    int n, m;
    cin >> n >> m;

    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            tot += A[i][j];
        }
    }

    int ans = 0, curr = 0;

    while (curr < tot) {
        ans++;
        int ix = 0, iy = 0;
        while (ix < n) {
            int found = -1;
            for (int ty = iy; ty < m; ty++) {
                if (A[ix][ty] == 1) found = ty;
            }

            if (found != -1) {
                for (int ty = iy; ty <= found; ty++) {
                    curr += A[ix][ty];
                    A[ix][ty] = 0;
                }
                iy = found;
            }
            ix++;
        }

    }
    cout << ans << '\n';
    

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}