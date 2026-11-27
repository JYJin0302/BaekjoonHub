#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    ll n, d;
    cin >> n >> d;
    vector<ll> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));


    ll l = A[0], r = A[n - 1];
    /*
    if (l >= 0) {
        cout << r * 2 + d;
        return;
    }
    if (r <= 0) {
        cout << abs(l) * 2 + d;
        return;
    }

    ll ans = (r - l + d) * 2;
    if ((r - l) * 2 <= d) {
        ans = min(ans, (r - l) * 2 + d);
    }
    else {
        ans = min(ans, (r - l) * 4);
    }
    */

    ll ans = 1e15;
    
    vector<int> ord;
    for (int i = 0; i < 4; i++) ord.push_back(i / 2);

    vector<ll> pos = { l, r };
    do {

        ll res = 0, cur = 0;
        vector<ll> dist(2, -1);
        for (auto f : ord) {
            if (dist[f] == -1) {
                dist[f] = 0;
                if (dist[1 - f] != -1) dist[1 - f] += abs(cur - pos[f]);
                res += abs(cur - pos[f]);
                cur = pos[f];
            }
            else {
                ll nd = abs(cur - pos[f]);
                if (dist[f] + nd <= d) nd = d - dist[f];

                if (dist[1 - f] != -1) dist[1 - f] += nd;
                res += nd;
                cur = pos[f];
            }
        }
        res += abs(cur);

        ans = min(ans, res);
    } while (next_permutation(all(ord)));
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   //  cin >> t;
    while (t--) solve();
}