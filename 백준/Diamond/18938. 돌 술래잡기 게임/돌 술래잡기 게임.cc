#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 1e15;
bool cmp(pair<ll, ll>& p1, pair<ll, ll>& p2) {
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y > p2.y;
}

vector<ll> num;
int getIdx(ll x) {
    return lower_bound(all(num), x) - num.begin();
}

int n;
ll segL[606060];
ll segR[606060];

void update(int ix, ll val, ll seg[]) {
    for (ix += n; ix; ix >>= 1) {
        seg[ix] = min(seg[ix], val);
    }
}

ll getVal(int l, int r, ll seg[]) {
    ll res = INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1) res = min(res, seg[--r]);
    }
    return res;
}

void solve() {

    cin >> n;

    bool ok = 0;
    vector<pair<ll, ll>> P;
    int U = 0, D = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        pair<ll, ll> t = mp(a + b, a - b);
        if (t.y == 0) ok = 1;
        else if (t.y > 0) {
            U++;
        }
        else {
            D++;
        }
        P.push_back(t);
        num.push_back(t.x + t.y);
    }



    if (ok) {
        cout << "Platina\n";
        return;
    }
    if (!U || !D) {
        cout << "Yuto\n";
        return;
    }
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    sort(all(P), cmp);
    for (int i = 1; i <= n * 2 + 10; i++) {
        segL[i] = segR[i] = INF;
    }

    for (auto& [a, b] : P) {
        if (b > 0) {
            int ix = getIdx(a + b);
            update(ix, 3 * b - a, segL);
            update(ix, b - a, segR);
        }
        else {
            int ix1 = getIdx(a + b + 4);
            ll val = getVal(ix1, n, segL);

            if (val - 3 * b - a < 10) {
                cout << "Platina\n";
                return;
            }

            val = getVal(0, ix1, segR);
            if (b > val - 3) {
                cout << "Platina\n";
                return;
            }
        }
    }

    num.clear();
    for (auto& [a, b] : P) {
        b *= -1;
        num.push_back(a + b);
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());
    sort(all(P), cmp);
    for (int i = 1; i <= n * 2 + 10; i++) {
        segL[i] = segR[i] = INF;
    }

    for (auto& [a, b] : P) {
        if (b > 0) {
            int ix = getIdx(a + b);
            update(ix, 3 * b - a, segL);
            update(ix, b - a, segR);
        }
        else {
            int ix1 = getIdx(a + b + 4);
            ll val = getVal(ix1, n, segL);

            if (val - 3 * b - a < 10) {
                cout << "Platina\n";
                return;
            }

            val = getVal(0, ix1, segR);
            if (b > val - 3) {
                cout << "Platina\n";
                return;
            }
        }
    }

    cout << "Yuto\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}