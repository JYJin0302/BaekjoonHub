#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 1e15;
ll n, u, d, s;

set<pair<ll, ll>> G;

void update(ll pos, ll val) {
    G.insert(mp(pos, val));
    auto iter = G.find(mp(pos, val));

    auto iter2 = iter;
    if (iter2 != G.end()) {
        iter2++;
        while (iter2 != G.end()) {
            auto [a, b] = *iter2;
            if (val - (a - pos) * d >= b) {
                iter2 = G.erase(iter2);
            }
            else break;
        }
    }

    iter2 = iter;
    if (iter2 != G.begin()) {
        iter2--;
        while (1) {
            auto [a, b] = *iter2;
            //cout << "--- test: " << a << ' ' << b << '\n';
            if (val - (pos - a) * u >= b) {
                iter2 = G.erase(iter2);
                if (iter2 == G.begin()) break;
                iter2--;
            }
            else break;
        }
    }
}

ll getVal(ll pos) {
    ll res = -INF;
    auto iter = G.lower_bound(mp(pos, -INF));
    if (iter != G.end()) {
        auto& [a, b] = *iter;
        res = max(res, b - (a - pos) * u);
    }
    if (iter != G.begin()) {
        --iter;
        auto& [a, b] = *iter;
        res = max(res, b - (pos - a) * d);
    }
    return res;
}

void solve() {

    cin >> n >> u >> d >> s;

    vector<pair<ll, pair<ll, ll>>> A(n);
    for (ll i = 0; i < n; i++) {
        ll t, l, m;
        cin >> t >> l >> m;
        A[i] = mp(t, mp(l, m));
    }
    sort(all(A));

    G.insert(mp(s, 0));

    ll ix = 0;
    while (ix < n) {

        ll nx = ix + 1;
        while (nx < n && A[nx].x == A[ix].x) nx++;

        //for (auto [a, b] : G) cout << '(' << a << ", " << b << ") ";
        //cout << '\n';

        if (nx == ix + 1) {
            ll currVal = getVal(A[ix].y.x);
            update(A[ix].y.x, currVal + A[ix].y.y);
        }
        else {
            vector<pair<ll, pair<ll, ll>>> currS;
            vector<pair<ll, ll>> newS;
            for (ll i = ix; i < nx; i++) {
                currS.push_back(mp(A[i].y.x, mp(getVal(A[i].y.x), A[i].y.y)));
            }

            ll tn = currS.size();
            newS.push_back(mp(currS[0].x, currS[0].y.x + currS[0].y.y));
            for (ll i = 1; i < tn; i++) {
                ll th = max(currS[i].y.x, newS[i - 1].y - d * (currS[i].x - currS[i - 1].x));
                newS.push_back(mp(currS[i].x, th + currS[i].y.y));
            }

            for (ll i = tn - 2; i >= 0; i--) {
                ll th = max(newS[i].y, newS[i + 1].y - u * (currS[i + 1].x - currS[i].x));
                newS[i].y = th;
            }

            vector<pair<ll, ll>> newS2(tn);
            newS2[tn - 1] = mp(currS[tn - 1].x, currS[tn - 1].y.x + currS[tn - 1].y.y);
            for (ll i = tn - 2; i >= 0; i--) {
                ll th = max(currS[i].y.x, newS2[i + 1].y - u * (currS[i + 1].x - currS[i].x));
                newS2[i] = mp(currS[i].x, th + currS[i].y.y);
            }

            for (ll i = 1; i < tn; i++) {
                ll th = max(newS2[i].y, newS2[i - 1].y - d * (currS[i].x - currS[i - 1].x));
                newS2[i].y = th;
            }

            for (ll i = 0; i < tn; i++) {
                newS[i].y = max(newS[i].y, newS2[i].y);
            }

            for (auto [a, b] : newS) {
                update(a, b);
            }

        }
        ix = nx;
    }

    ll ans = max(0ll, getVal(s));
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}