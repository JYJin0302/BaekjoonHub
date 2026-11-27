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
        for (int j = i; j < 100; j++) {
            int pv = 0;
            for (int k = 0; k < 100; k++) {
                bool ok = 1;
                for (int f = i; f <= j; f++) {
                    if (A[f][k] == 0) ok = 0;
                }
                if (ok) pv++;
                else pv = 0;
                ans = max(ans, pv * (j - i + 1));
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