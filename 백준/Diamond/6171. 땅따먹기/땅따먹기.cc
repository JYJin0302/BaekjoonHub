#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ld getInter(ll a, ll b, ll c, ll d) {
    a -= c; d -= b;
    return 1.0 * d / a;
}

void solve() {

    int n;
    cin >> n;
    vector<pair<ll, ll>> A(n), B;
    for (auto& i : A) cin >> i.x >> i.y;

    sort(all(A));

    for (auto [a, b] : A) {
        while (!B.empty() && B.back().y <= b) B.pop_back();
        B.push_back(mp(a, b));
    }

    int sn = B.size();

    vector<pair<ll, ll>> L;
    vector<ld> pos;

    vector<ll> dp(sn + 1);
    for (int i = 1; i <= sn; i++) {
        auto [a, b] = B[i - 1];

        // insert b * x + dp[i-1];
        while (!L.empty()) {
            auto [ta, tb] = L.back();
            ld tp = getInter(ta, tb, b, dp[i-1]);
            if (tp <= pos.back()) {
                L.pop_back();
                pos.pop_back();
            }
            else {
                L.push_back(mp(b, dp[i-1]));
                pos.push_back(tp);
                break;
            }
        }
        if (L.empty()) {
            L.push_back(mp(b, dp[i-1]));
            pos.push_back(0);
        }


        ll x = a;
        auto ix = lower_bound(all(pos), x) - pos.begin();
        if (ix == L.size()) ix--;
        else if (L[ix].x == x) {}
        else ix--;
        auto [ta, tb] = L[ix];

        dp[i] = ta * x + tb;


    }

    cout << dp[sn] << '\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}