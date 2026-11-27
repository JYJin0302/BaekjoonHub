#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>

const ll mod = 1e9 + 7;

void solve() {

    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    sort(all(A));
    reverse(all(A));

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans * 2 + A[i];
        ans %= mod;
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