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

    int n, m;
    cin >> n >> m;
    vector<int> res(202);

    int ans1 = 0;
    vector<pair<int, string>> ans;
    for (int i = 0; i < n; i++) {
        int cnt = 0, mx = 0;
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '*') cnt = 0;
            else cnt++;
            mx = max(mx, cnt);
        }
        string s;
        cin >> s;
        ans.push_back(mp(mx, s));
        if (res[mx]) {}
        else {
            res[mx]++;
            ans1++;
        }
    }
    cout << ans1 << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}