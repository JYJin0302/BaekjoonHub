#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll n, c, p, q;

void solve() {
    cin >> n >> c >> p >> q;
    string s;
    cin >> s;

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Y') cnt[i+1]++;
        cnt[i+1] += cnt[i];
    }

    int rank = 0;
    int pv = 0;
   
    int ix = c;
    while (ix <= n) {

        for (int i = ix - c; i >= pv && i >= ix - 2*c; i--) {
            ll y = cnt[ix] - cnt[i];
            ll x = ix - i;
            if (y * q >= x * p) {
                // rank up
                rank++;
                pv = ix;
            }
        }
        ix++;

    }

    cout << rank << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}