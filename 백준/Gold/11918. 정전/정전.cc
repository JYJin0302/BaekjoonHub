#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void insert(vector<pair<ll, ll>>& v, ll l, ll r) {
    if (v.empty() || v.back().y < l) v.push_back(mp(l, r));
    else v.back().y = r;
}

void solve() {

    ll n, k;
    cin >> n >> k;
    
    vector<pair<ll, ll>> L, R;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));

    for (int i = 0; i < n; i++) {
        ll x = A[i];
        if (i & 1) insert(R, x - k, x + k);
        else insert(L, x - k, x + k);
    }

    ll ans = 0;
    int i1 = 0, i2 = 0;
    while (i1 < L.size() && i2 < R.size()) {
        ll tl = max(L[i1].x, R[i2].x);
        ll tr = min(L[i1].y, R[i2].y);
        if (tr >= tl) ans += tr - tl;

        if (L[i1].y < R[i2].y) i1++;
        else i2++;
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