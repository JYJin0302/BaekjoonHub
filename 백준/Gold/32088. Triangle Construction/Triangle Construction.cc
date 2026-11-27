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

    ll tot = 0, mx = 0;
    for (auto f : A) {
        tot += f;
        mx = max(mx, f);
    }

    if (mx / 2 >= tot - mx) {
        cout << tot - mx << '\n';
    }
    else cout << tot / 3 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}