#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    ll h;
    cin >> h;

    int n, q;
    cin >> n >> q;
    
    multiset<ll> st;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        tot += x;
        st.insert(x);
    }

    while (tot - *st.begin() >= h) {
        tot -= *st.begin();
        st.erase(st.begin());
    }

    if (tot < h) cout << -1 << '\n';
    else cout << st.size() << '\n';

    while (q--) {

        ll x;
        cin >> x;
        st.insert(x);
        tot += x;

        while (tot - *st.begin() >= h) {
            tot -= *st.begin();
            st.erase(st.begin());
        }

        if (tot < h) cout << -1 << '\n';
        else cout << st.size() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}