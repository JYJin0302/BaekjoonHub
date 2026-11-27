#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll mod = 1e9 + 7;
const ll p = 1000003;

set<int> st[101];

void solve() {

    int n, k;
    cin >> n >> k;

    ll tv = 1;
    for (int i = 0; i < k; i++) {
        tv = tv * p % mod;
    }

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v = vector<int>(x);
        for (auto& f : v) cin >> f;
        ll val = 0;
        for (int j = 0; j < x; j++) {
            val = val * p % mod;
            val = (val + v[j]) % mod;
            if (j >= k) {
                val -= v[j - k] * tv % mod;
                if (val < 0) val += mod;
            }
            if (j >= k - 1) st[i].insert(val);
        }
    }

    vector<int> rev = v;
    reverse(all(rev));

    int sz = rev.size();
    vector<pair<int, int>> res(sz);
    ll val = 0;
    for (int j = 0; j <sz; j++) {
        val = val * p % mod;
        val = (val + rev[j]) % mod;
        if (j >= k) {
            val -= rev[j - k] * tv % mod;
            if (val < 0) val += mod;
        }
        if (j >= k - 1) {
            int tj = j - (k - 1);
            tj = sz - 1 - tj;
            res[tj].second = val;
        }
    }
    val = 0;
    for (int j = 0; j < sz; j++) {
        val = val * p % mod;
        val = (val + v[j]) % mod;
        if (j >= k) {
            val -= v[j - k] * tv % mod;
            if (val < 0) val += mod;
        }
        if (j >= k - 1) res[j].first = val;
    }

    /*for (auto f : res) cout << f.first << ' ' << f.second << " | ";
    cout << '\n';*/

    for (int i = k - 1; i < sz; i++) {

        bool ok = 1;
        for (int j = 0; j < n - 1; j++) {
            auto f = st[j].find(res[i].first);
            if (f != st[j].end()) continue;
            f = st[j].find(res[i].second);
            if (f == st[j].end()) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}