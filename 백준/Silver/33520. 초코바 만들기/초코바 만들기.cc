#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {
    int n; cin >> n;

    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        a = max(a, u);
        b = max(b, v);
    }
    cout << a * b << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}