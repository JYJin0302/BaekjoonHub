#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

ll mod = 1e9 + 7;
vector<ll> seg;
vector<pair<ll, ll>> lazy;

pair<ll, ll> addp(pair<ll, ll> a, pair<ll, ll> b) {
    return { a.first * b.first % mod, (a.second * b.first + b.second) % mod };
}
bool checkP(pair<ll, ll> a) {
    return (a.first == 1 && a.second == 0);
}

void init(int l, int r, int n) {
    if (l == r) return;
    int mid = (l + r) / 2;
    init(l, mid, n * 2);
    init(mid + 1, r, n * 2 + 1);
    seg[n] = (seg[n * 2] + seg[n * 2 + 1]) % mod;
}

void update(ll l, ll r, ll n, ll t, ll sl, ll sr, ll v) {

    if (!checkP(lazy[n])) {
        ll a, b;
        tie(a, b) = lazy[n];

        seg[n] = (seg[n] * a % mod + (r - l + 1) * b % mod) % mod;
        if (l != r) {
            lazy[n * 2] = addp(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = addp(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = { 1, 0 };
    }

    if (l > sr || r < sl) return;
    if (l >= sl && r <= sr) {
        if (t == 1) {
            lazy[n] = addp(lazy[n], { 1, v });
        }
        else if (t == 2) {
            lazy[n] = addp(lazy[n], { v, 0 });
        }
        else {
            lazy[n] = addp(lazy[n], { 0, v });
        }
        ll a, b;
        tie(a, b) = lazy[n];

        seg[n] = (seg[n] * a % mod + (r - l + 1) * b % mod) % mod;
        if (l != r) {
            lazy[n * 2] = addp(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = addp(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = { 1, 0 };
        return;
    }

    ll mid = (l + r) / 2;
    update(l, mid, n * 2, t, sl, sr, v);
    update(mid + 1, r, n * 2 + 1, t, sl, sr, v);
    seg[n] = (seg[n * 2] + seg[n * 2 + 1]) % mod;
}

ll ssum(int l, int r, int n, int sl, int sr) {
    if (!checkP(lazy[n])) {
        ll a, b;
        tie(a, b) = lazy[n];

        seg[n] = (seg[n] * a % mod + (r - l + 1) * b % mod) % mod;
        if (l != r) {
            lazy[n * 2] = addp(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = addp(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = { 1, 0 };
    }
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int mid = (l + r) / 2;
    return (ssum(l, mid, n * 2, sl, sr) + ssum(mid + 1, r, n * 2 + 1, sl, sr)) % mod;
}

void solve() {

    ll n;
    cin >> n;

    ll size = 1;
    while (size < n) size *= 2;

    seg = vector<ll>(size * 2);
    lazy = vector<pair<ll, ll>>(size * 2, { 1, 0 });

    for (int i = 0; i < n; i++) {
        cin >> seg[size + i];
        seg[size + i] %= mod;
    }

    init(size, size * 2 - 1, 1);

    int q;
    cin >> q;
    while (q--) {
        ll t, a, b, c;
        cin >> t;
        if (t == 4) {
            cin >> a >> b;
            cout << ssum(size, size * 2 - 1, 1, size + a - 1, size + b - 1) << '\n';
        }
        else {
            cin >> a >> b >> c;

            update(size, size * 2 - 1, 1, t, size + a - 1, size + b - 1, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    while (T--) {
        solve();
    }
}