#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<ll, ll>> A(n);
    for (auto& i : A) cin >> i.y;
    for (auto& i : A) cin >> i.x;

    vector<ll> B(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
        B[i] += B[i - 1];
    }

    sort(all(A));
    vector<pair<ll, ll>> C;
    for (auto [a, b] : A) {
        while (!C.empty() && C.back().y >= a - b) {
            b += C.back().y - C.back().x;
            C.pop_back();
        }
        C.push_back(mp(a - b, a));
    }
    vector<ll> sC;
    for (int i = 0; i < (int)C.size(); i++) {
        sC.push_back(C[i].y - C[i].x + (i ? sC[i - 1] : 0));
    }


    while (q--) {
        ll x;
        cin >> x;

        ll able = 0;
        int ix = lower_bound(all(C), mp(x, -1ll)) - C.begin();
        if (ix && C[ix - 1].y >= x) x = C[ix - 1].y;        
        able = x - (ix ? sC[ix - 1] : 0);
        cout << lower_bound(all(B), able + 1) - B.begin() - 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}