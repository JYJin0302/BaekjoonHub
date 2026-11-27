#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int L[101010], R[101010];

void solve() {

    int n;
    cin >> n;
    vector<ll> W(n + 2), H(n+2);
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> H[i];
        L[i] = R[i] = i;
    }

    vector<ll> ans(n + 2);

    H[0] = H[n + 1] = 1e9;
    int ix = min_element(all(H)) - H.begin();
    int ansCnt = 0;
    ll curT = 0;
    while (ansCnt < n) {

        ans[ix] = curT + W[ix];
        ansCnt++;
        if (ansCnt == n) break;

        ll mn = min(H[L[ix] - 1], H[R[ix] + 1]);
        curT += W[ix] * (mn - H[ix]);
        if (mn == H[R[ix] + 1]) {
            W[R[ix] + 1] += W[ix];
            L[R[ix] + 1] = L[ix];
            ix = R[ix] + 1;
            while (H[R[ix] + 1] < H[ix]) ix = R[ix] + 1;
        }
        else {
            W[L[ix] - 1] += W[ix];
            R[L[ix] - 1] = R[ix];
            ix = L[ix] - 1;
            while (H[L[ix] - 1] < H[ix]) ix = L[ix]-  1;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}