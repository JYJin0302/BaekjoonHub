#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    ll n;
    cin >> n;

    int k;
    cin >> k;
    vector<ll> A(k);
    for (auto& i : A) cin >> i;

    vector<ll> od, ev;
    for (int i = 1; i < (1 << k); i++) {
        ll v = 1;
        int cnt = 0;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                cnt++;
                v *= A[j];
            }
        }

        if (cnt & 1) od.push_back(v);
        else ev.push_back(v);
    }

    ll l = 1, r = 1e18, res = -1;
    while (l <= r) {
        ll md = (l + r) >> 1;

        ll cnt = md;
        for (auto f : od) cnt -= md / f;
        for (auto f : ev) cnt += md / f;

        if (cnt >= n) {
            res = md;
            r = md - 1;
        }
        else l = md + 1;
    }

    cout << res << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}