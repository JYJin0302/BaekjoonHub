#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {
    
    int tot = 0, mn = 101;
    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;

        if (x & 1) {
            tot += x;
            mn = min(mn, x);
        }
    }

    if (tot == 0) cout << -1;
    else {
        cout << tot << '\n' << mn << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}