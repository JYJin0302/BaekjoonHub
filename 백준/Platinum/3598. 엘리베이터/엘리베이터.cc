#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    ll h, a, b, c;
    cin >> h >> a >> b >> c;
    h--;

    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    vector<ll> dist(c, -1);
    
    set<ll> st;
    st.insert(0);
    while (!st.empty()) {
        ll val = *st.begin(); 
        st.erase(st.begin());

        if (dist[val%c] != -1) continue;
        dist[val%c] = val;

        ll nv = val + a;
        if (dist[nv % c] == -1) st.insert(nv);

        nv = val + b;
        if (dist[nv % c] == -1) st.insert(nv);
    }

    ll ans = 0;
    for (int i = 0; i < c; i++) {
        if (dist[i] != -1 && dist[i] <= h) {
            ans += (h - dist[i]) / c + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}