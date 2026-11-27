#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> A(m), B(m);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    if (n == m) {
        bool ok = 1;
        for (int i = 0; i < m; i++) {
            if (A[i] != B[i]) ok = 0;
        }

        if (ok) cout << 0;
        else cout << -1;
        return 0;
    }

    vector<pair<ll, ll>> C(m);
    for (int i = 0; i < m; i++) {
        C[i] = { B[i], A[i] };
    }
    sort(C.begin(), C.end());

    for (int i = 1; i < m; i++) {
        if (C[i].first == C[i - 1].first) {
            cout << -1;
            return 0;
        }

        if (C[i].second < C[i - 1].second) C[i].second += n;
    }

    if (C[0].second + n < C[m - 1].second) {
        cout << -1;
        return 0;
    }
    bool tmp = 0;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += C[i].second - C[i].first;
        if (C[i].second < C[i].first) tmp = 1;
        if (i > 0 && C[i].second < C[i - 1].second) {
            cout << -1;
            return 0;
        }
    }

    if (tmp) ans += n * m;
    cout << ans;
}