#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

int n, m, k;
const int mod = 1e9 + 9;


void solve() {
    cin >> n >> m >> k;

    vector<ll> cur(n + 1, 1);
    while (m > 1) {
        int nn = min(k + 1, (int)cur.size() + n);
        vector<ll> nc(nn);
        nc[0] = cur[0];
        for (int i = 1; i < nn; i++) {
            nc[i] = nc[i - 1] + (i < (int)cur.size() ? cur[i] : 0);
            if (i >= n + 1) nc[i] += mod - cur[i - n - 1];
            nc[i] %= mod;
        }
        m--;
        cur = nc;
    }

    if (cur.size() >= k + 1) cout << cur[k] << '\n';
    else cout << 0;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}