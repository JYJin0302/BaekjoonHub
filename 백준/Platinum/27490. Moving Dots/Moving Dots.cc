#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
ll p2[3030];

void solve() {

    int n;
    cin >> n;

    p2[0] = 1;
    for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % mod;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int len = A[j] - A[i];
            ll val = 0;
            int lx = lower_bound(all(A), A[i] - len) - A.begin();
            if (A[i] - A[lx] <= len) lx--;
            val = p2[lx + 1];

            int rx = lower_bound(all(A), A[j] + len) - A.begin();
            val *= p2[n - rx];
            val %= mod;

            ans = (ans + val) % mod;

        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}