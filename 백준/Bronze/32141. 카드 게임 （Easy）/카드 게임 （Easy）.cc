#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    ll n, h;
    cin >> n >> h;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    int ans = 0;
    ll tot = 0;
    for (auto f : A) {
        tot += f;
        ans++;
        if (tot >= h) break;
    }

    if (tot < h) ans = -1;
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}