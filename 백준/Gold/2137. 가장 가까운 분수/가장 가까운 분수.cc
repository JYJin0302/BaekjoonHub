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

void solve() {

    ll n, d;
    cin >> n >> d;

    pair<ll, ll> ans = mp(1, 2), diff = mp(1, 1);
    

    for (int i = 2; i <= 32767; i++) {
        int ni = n * i / d;
        for (int j = ni; j <= ni + 1; j++) {
            if (j == 0 || j >= i) continue;
            if (i == d && j == n) continue;
            ll g = gcd(i, j);
            if (g != 1) continue;


            ll nd = d * i;
            ll nn = abs(d * j - n * i);

            g = gcd(nd, nn);
            nd /= g;
            nn /= g;

            if (diff.x * nd > diff.y * nn) {
                ans = mp(j, i);
                diff = mp(nn, nd);
            }
            else if (diff.x * nd == diff.y * nn) {
                if (ans.x * i > ans.y * j) {
                    ans = mp(j, i);
                    diff = mp(nn, nd);
                }
            }

        }
    }

    cout << ans.x << ' ' << ans.y;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}