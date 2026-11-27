#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    
    ll h; cin >> h;

    int t = log2(h);
    if ((1ll << t) != h || h == 1 || t & 1) {
        cout << -1;
        return;
    }
    int tt = log2(t);
    if ((1ll << tt) != t || tt == 1) {
        cout << -1;
        return;
    }

    cout << tt + 1 << ' ' << tt + 1 << '\n';
    for (int i = 0; i < tt; i++) cout << 1 << ' ';
    cout << '\n';
    for (int i = 0; i < tt - 1; i++)  cout << 1 << ' ';
    cout << tt << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}