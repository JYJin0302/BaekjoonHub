#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n, k, c, r;
    cin >> n >> k >> c >> r;

    vector<ll> base(k), s(k), p(k);
    for (auto& i : base)cin >> i;
    for (auto& i : s)cin >> i;
    for (auto& i : p)cin >> i;

    vector<int> cnt(k);
    int pre = 0;
    int piro = 0;
    ll ans = 0;
    
    bool broken = 0;
    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;
        if (x == 0) {
            piro = max(0, piro - r);
            pre = 0;
        }
        else {
            x--;
            piro += p[x];

            if (piro > 100) {
                broken = 1;
            }
            ll add = base[x];
            add *= 100 + pre * c;
            add *= 100 + cnt[x] * s[x];

            add /= 10000;
            ans += add;

            cnt[x]++;
            pre++;
        }
    }
    if (broken) ans = -1;
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}