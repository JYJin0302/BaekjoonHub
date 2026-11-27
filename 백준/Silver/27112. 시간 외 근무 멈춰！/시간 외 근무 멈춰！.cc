#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % m;
        b = b * b % m;
        ex /= 2;
    }
    return res;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


void solve() {

    int n;
    cin >> n;

    vector<pair<ll, ll>> A(n), B;
    for (auto& i : A) cin >> i.first >> i.second;
    sort(A.begin(), A.end());

    B.push_back(A[0]);
    for (int i = 1; i < n; i++) {
        if (A[i].first == B.back().first) {
            B.back().second += A[i].second;
        }
        else B.push_back(A[i]);
    }

    bool ok = 1;
    ll ans = 0;
    ll pv = 0, rm1 = 0, rm2 = 0, tmp = 0;

    for (auto i : B) {
        ll a, b;
        tie(a, b) = i;

        ll dis = a - pv;
        rm2 += dis;
        rm1 += dis;
        tmp = a / 7 * 2 + (a % 7 == 6);

        rm1 -= tmp;
        ll nd = min(rm1, b);
        b -= nd;
        rm1 -= nd;

        if (b > 0) {
            rm2 -= b;
            ans += b;

            if (rm2 < 0) ok = 0;
        }


        rm1 += tmp;
        pv = a;

    }
    if (ok) cout << ans;
    else cout << -1;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}