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

    int ans = 8;
    int cnt = 1;
    while (cnt < n) {
        ans++;
        cnt <<= 1;
    }
    if (cnt == n) ans += 2;
    else ans++;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}