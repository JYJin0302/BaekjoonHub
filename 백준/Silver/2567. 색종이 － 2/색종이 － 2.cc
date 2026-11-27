#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int A[111][111];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                A[a + j][b + k] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (A[i][j] == 1) {
                ans += 4;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (A[ni][nj]) ans--;
                }

            }
        }
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