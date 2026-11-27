#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n;
    cin >> n;

    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.insert(x);
    }

    ll ans = 0;
    while (st.size() > 1) {
        int x1 = *st.begin(); st.erase(st.begin());
        int x2 = *st.begin(); st.erase(st.begin());
        ans += x1 + x2;
        st.insert(x1 + x2);
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