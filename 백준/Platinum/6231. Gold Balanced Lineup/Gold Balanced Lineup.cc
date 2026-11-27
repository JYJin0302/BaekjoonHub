#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int mod3 = 100000007;
void solve() {

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    if (k == 1) {
        cout << n << '\n';
        return;
    }
    vector<ll> b(k), b2(k);
    ll pv = 1;
    b[0] = b2[0] = pv;
    b[k - 1] = mod - pv;
    b2[k - 1] = mod2 - pv;
    for (int i = 1; i < k - 1; i++) {
        pv = pv * mod2 % mod;
        b[i] = pv;
        b[k - 1] = (b[k - 1] + mod - b[i]) % mod;
    }
    pv = 1;
    for (int i = 1; i < k - 1; i++) {
        pv = pv * mod3 % mod2;
        b2[i] = pv;
        b2[k - 1] = (b2[k - 1] + mod2 - b2[i]) % mod2;
    }


    map<pair<ll, ll>, ll> res;
    ll c1 = 0, c2 = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (A[i] & (1 << j)) {
                c1 = (c1 + b[j]) % mod;
                c2 = (c2 + b2[j]) % mod2;
            }
        }

        if (c1 + c2 == 0 || res[mp(c1, c2)]) {
            ans = max(ans, i+1 - res[mp(c1, c2)]);
        }
        else res[mp(c1, c2)] = i+1;
    }

    cout << ans << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}