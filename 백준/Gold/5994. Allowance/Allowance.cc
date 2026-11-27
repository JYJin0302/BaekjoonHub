#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    ll n, c;
    cin >> n >> c;
    vector<pair<ll, ll>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;
    sort(A.rbegin(), A.rend());

    ll ans = 0;

    while (1) {

        ll cur = 0;
        vector<ll> need(n);
        for (int i = 0; i < n; i++) {
            need[i] = min(A[i].second, (c - cur) / A[i].first);
            cur += need[i] * A[i].first;
        }

        if (cur < c) {
            for (int i = n - 1; i >= 0; i--) {
                if (need[i] + 1 <= A[i].second) {
                    need[i]++;
                    cur += A[i].first;
                    break;
                }
            }
        }
        if (cur < c) break;

        ll t = 1e9;
        for (int i = 0; i < n; i++) {
            if (need[i] != 0) t = min(t, A[i].second / need[i]);
        }

       /* cout << "Go: " << t << " | ";
        for (auto f : need) cout << f << ' ';
        cout << '\n';*/

        ans += t;
        for (int i = 0; i < n; i++) {
            A[i].second -= need[i] * t;
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