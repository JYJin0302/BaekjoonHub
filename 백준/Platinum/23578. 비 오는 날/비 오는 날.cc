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

    vector<ll> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;
    multiset<pair<ll, pair<ll, ll>>> st;
    for (auto f : A) {
        ans += f;
        st.insert(mp(f * 3, mp(f, 3)));
    }

    for (int i = 0; i < n - 2; i++) {
        ans += (*st.begin()).x;
        auto [a, b] = (*st.begin()).y;
        st.erase(st.begin());
        st.insert(mp(a * (b + 2), mp(a, b + 2)));
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