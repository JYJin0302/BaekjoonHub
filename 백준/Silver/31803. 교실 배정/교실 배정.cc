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
    __int128 ans = 1;
    
    if (n & 1) {
        ans *= n;
        n--;
    }
    
    for(int i = n; i > n/2; i--) ans *= i;
    for(int i = 0; i < n/2; i++) ans /= 2;
    ll res = (ll)ans;
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}