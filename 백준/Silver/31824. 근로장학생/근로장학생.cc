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

    vector<pair<string, string>> A;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        A.push_back(mp(a, b));
    }
    sort(all(A));

    while (m--) {
        bool ok = 0;
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            for (auto& f : A) {
                if (j + f.x.size() <= s.size() && s.substr(j, f.x.size()) == f.x) {
                    cout << f.y;
                    ok = 1;
                }
            }
        }

        if (!ok) cout << -1;
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}