#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

ll n, k;

ll getCnt(ll val) {
    ll cur = 1;
    int len = 1;
    ll ret = 0;
    while (val >= cur * 10) {
        ret += 9 * cur * len;
        len++;
        cur *= 10;
    }
    
    ret += (val - cur + 1) * len;
    return ret;
}

void solve() {

    ll l = 1, r = 2e8, res = -1;

    while (l <= r) {
        ll md = (l + r) >> 1;
        if (getCnt(md) < n) {
            res = md;
            l = md + 1;
        }
        else r = md - 1;
    }

    string s;
    ll cur = 0;
    int ix = 0;

    if (res == -1) {
        cur = 1;
        ix = 0;
        s = to_string(1);
    }
    else {
        cur = res + 1;
        ix = n - getCnt(res) - 1;
        s = to_string(cur);
    }

    while (k--) {
        cout << s[ix++];
        
        if (ix == s.size()) {
            ix = 0;
            cur++;
            s = to_string(cur);
        }
    }
    cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    cin >> n >> k;
    while (n + k) {
        solve();
        cin >> n >> k;
    }
        
    return 0;
}