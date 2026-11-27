#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    ll n;
    cin >> n;

    int ans = 0;
    while (n != 1) {
        if (n & 1) n = n * 3 + 1;
        else n >>= 1;
        ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}