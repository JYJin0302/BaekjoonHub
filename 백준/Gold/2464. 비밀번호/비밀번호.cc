#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    ll x;
    cin >> x;

    vector<int> b(64), cnt(64);
    int mx = 0;
    for (int i = 0; i < 64; i++) {
        if (x & (1ll << i)) b[i] = 1, mx = i;
        cnt[i] = b[i];
        if (i) cnt[i] += cnt[i - 1];
    }

    if (x + 1 == (1ll << mx + 1)) cout << 0 << ' ';
    else {
        for (int i = 0; i < 64; i++) {
            if (!b[i] && b[i + 1]) {
                ll nv = x >> i + 2;
                nv <<= (i + 2ll);

                for (int j = 0; j < cnt[i + 1]; j++) {
                    nv += 1ll << (i - j);
                }
                cout << nv << ' ';
                break;
            }
        }
    }

    for (int i = 0; i < 64; i++) {
        if (b[i] && !b[i + 1]) {
            ll nv = x >> i + 2;
            nv <<= (i + 2ll);
            nv += 1ll << i + 1;

            for (int j = 0; j < cnt[i + 1] - 1; j++) {
                nv += 1ll << j;
            }
            cout << nv << ' ';
            break;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}