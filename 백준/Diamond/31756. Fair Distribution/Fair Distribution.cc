#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

bitset<400010> bs;
void solve() {

    int n;
    cin >> n;

    int g = 0;
    vector<int> G(n), R(n);
    for (int i = 0; i < n; i++) cin >> G[i] >> R[i];

    if (n == 1) {
        cout << "N\n";
        return;
    }

    for (auto f : R) g = gcd(g, f);
    if (g == 1) {
        cout << "Y\n";
        return;
    }


    int b = 200000;
    int tot = 0;
    bs[b] = 1;
    sort(all(G));
    bool ok = 0;

    int ix = 0;
    while (ix < n) {
        int nx = ix;
        while (nx < n && G[nx] == G[ix]) nx++;
        int len = nx - ix;
        tot += G[ix] * len;
        if (G[ix] == 0) {
            ok = 1;
        }
        else {
            for (int j = 1; len; j <<= 1) {
                int val = min(j, len);
                len -= val;
                bs = (bs << val * G[ix]) | (bs >> val * G[ix]);
            }
        }
        ix = nx;
    }



    for (int i = 0; i <= 400000; i++) {
        if (!bs[i]) continue;
        int v = i - b;

        if ((ok || abs(v) != tot) && abs(v) % g == 0) {
            cout << "Y\n";
            return;
        }
    }
    cout << "N\n";



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}