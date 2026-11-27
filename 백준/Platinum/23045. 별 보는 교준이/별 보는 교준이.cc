#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solve() {

    int n;
    cin >> n;

    vector<pair<ll, ll>> A(n);
    for (auto& [a, b] : A) cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<pair<ll, ll>> B;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ll a = A[j].x - A[i].x;
            ll b = A[j].y - A[i].y;

            ll g = gcd(abs(a), abs(b));
            a /= g, b /= g;
            B.push_back(mp(a, b));
        }
        sort(all(B));
        B.erase(unique(all(B)), B.end());
       
        ans += B.size();
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