#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second



void solve() {

    int n;
    cin >> n;

    ll L, R, H;
    cin >> L >> R >> H;

    map<ll, int> tmp;
    tmp[L] = 0;
    tmp[R + 1] = 1;
    for (int i = 0; i < n; i++) {
        ll x, a, b;
        cin >> x >> a >> b;

        ll d = H * b / a;
        ll tl, tr;
        if (H * b % a == 0 && d * a / b == H) {
            tl = x - d + 1;
            tr = x + d - 1;
        }
        else {
            tl = x - d;
            tr = x + d;
        }

       // cout << tl << ' ' << tr << '\n';
        tl = max(tl, L);
        tr = min(tr, R);
        if (tl <= tr) {
            tmp[tl]++;
            tmp[tr + 1]--;
        }
    }

    vector<ll> ans(n + 1);

    ll cur = 0, pv = L;
    for (auto [a, b] : tmp) {
        if (pv <= a - 1) {
            ans[cur] += a - pv;
        }
        pv = a;
        cur += b;
    }

    for (int i = 0; i <= n; i++) {
        if (i) ans[i] += ans[i - 1];
        cout << ans[i] << '\n';
        
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}