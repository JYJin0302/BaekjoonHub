#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 4e18;

ll n, c;
set<pair<ll, ll>> st;

ll getVal(ll pos) {
    auto ix = st.lower_bound(mp(pos, -INF));
    ll res = -INF;
    if (ix != st.end()) {
        res = max(res, -abs((*ix).x - pos) * c + (*ix).y);
    }
    if (ix != st.begin()) {
        ix--;
        res = max(res, -abs((*ix).x - pos) * c + (*ix).y);
    }
    return res;
}

void update(ll pos, ll val) {
    st.insert(mp(pos, val));
    auto ix = st.lower_bound(mp(pos, val));
    
    auto iter1 = ix;
    iter1++;
    while (iter1 != st.end()) {
        auto [a, b] = *iter1;
        if (b <= val - abs(a - pos) * c) {
            iter1 = st.erase(iter1);
        }
        else break;
    }
    iter1 = ix;

    while (iter1 != st.begin()) {
        iter1--; 
        auto [a, b] = *iter1;
        if (b <= val - abs(a - pos) * c) {
            iter1 = st.erase(iter1);
        }
        else break;
    }

}

void solve() {

    string s;
    cin >> s;

    int ans = 0;
    int n;
    cin >> n;
    while (n--) {
        string a;
        cin >> a;

        if (s.substr(0, 5) == a.substr(0, 5)) ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}