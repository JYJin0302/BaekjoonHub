#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int cnt[101][101];
int cntH[101], cntV[101];
int cntR[222], cntL[222];

void solve() {

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a][b]++;
        cntH[a]++;
        cntV[b]++;
        cntR[a + b]++;
        cntL[a - b + 100]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tot = 0;
            tot += cntH[i] - cnt[i][j];
            tot += cntV[j] - cnt[i][j];
            tot += cntR[i + j] - cnt[i][j];
            tot += cntL[i - j + 100] - cnt[i][j];
            tot += cnt[i][j];

            if (tot == k) ans++;
        }
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}