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

    vector<ll> val = { 1 };
    for (int i = 1; i < 33; i++) val.push_back(val.back() * -2);

    vector<pair<ll, ll>> r = { mp(0, 1) };
    for (int i = 1; i < 33; i++) {
        pair<ll, ll> nxt = r.back();
        nxt.x += val[i];
        nxt.y += val[i];

        nxt.x = min(nxt.x, r.back().x);
        nxt.y = max(nxt.y, r.back().y);
        r.push_back(nxt);
    }

    vector<int> res;
    int ix = 0;
    while (r[ix].x > n || r[ix].y < n)ix++;

    while (ix) {
        if (r[ix - 1].x > n || r[ix - 1].y < n) {
            res.push_back(1);
            n -= val[ix];
        }
        else res.push_back(0);
        ix--;
    }
    res.push_back(n);
    for (auto f : res) cout << f;
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}