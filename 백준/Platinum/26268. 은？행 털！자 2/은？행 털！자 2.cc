#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> num;
vector<ll> seg;

int getIdx(ll x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

void update(int l, int r, int n, int u, ll  v) {
    if (r < u || l > u) return;
    if (l == u && r == u) {
        seg[n] = v;
        return;
    }
    int m = (l + r) / 2;
    update(l, m, n * 2, u, v);
    update(m + 1, r, n * 2 + 1, u, v);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

ll ssum(int l, int r, int n, int sl, int sr) {

    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) / 2;
    return max(ssum(l, m, n * 2, sl, sr), ssum(m + 1, r, n * 2 + 1, sl, sr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<pair<ll, ll>> A(n);

    for (auto& i : A) {

        ll a, b, c;
        cin >> a >> b >> c;
        i.first = b-a, i.second = c;
        num.push_back(b-a);
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    

    int sz = num.size();
    int sn = 1;
    while (sn < sz) sn *= 2;
    seg = vector<ll>(sn * 2);

    ll ans = 0;
    for (auto i : A) {
        ll a, b;
        tie(a, b) = i;

        a = getIdx(a);

        ll nval = ssum(0, sn - 1, 1, 0, a) + b;
        ans = max(ans, nval);
        update(0, sn - 1, 1, a, nval);
    }

    cout << ans;

}