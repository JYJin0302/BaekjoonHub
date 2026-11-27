#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A(n), B(m);
    for (auto& i : A) cin >> i.y >> i.x;
    for (auto& i : B) cin >> i.y >> i.x;

    sort(all(A));
    sort(all(B));
    int ix = m - 1;

    ll ans = 0;
    multiset<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (ix >= 0 && B[ix].x >= A[i].x) {
            st.insert(B[ix].y);
            ix--;
        }

        auto iter = st.lower_bound(A[i].y);
        if (iter == st.end()) {
            cout << -1 << '\n';
            return;
        }

        ans += *iter;
        st.erase(iter);
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