#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


const int mod = 1e9+7;
void solve() {
    
    ll p, q, r;
    cin >> p >> q >> r;

    ll ans = 0;
    // p == 1
    ans += min(q, r);

    // q == 1
    ans += p - 1;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}