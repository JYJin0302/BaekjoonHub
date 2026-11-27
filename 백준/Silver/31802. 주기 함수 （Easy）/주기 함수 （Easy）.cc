#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int cnt[1001010];
bool chk(int x) {
    string ts = to_string(x);
    if (ts.size() <= 2) return 0;
    int ix = 1;
    while (ix < ts.size() && ts[ix] > ts[ix - 1]) ix++;
    if (ix == ts.size() || ix == 1) return 0;

    while (ix < ts.size() && ts[ix] < ts[ix - 1]) ix++;
    return ix == ts.size();

}

void solve() {

    int p;
    cin >> p;
    vector<ll> A(p);
    for (auto& i : A) cin >> i;

    ll l, r;
    cin >> l >> r;

    ll tot = 0;
    for (auto f : A) tot += f;

    ll d = (r - l) / p;
    ll ans = d * tot;

    l += d * p;

    d = r - l;
    l = (l % p + p) % p;

    while (d--) {
        ans += A[l];
        l = (l + 1) % p;
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}