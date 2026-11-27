#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>


void solve() {

    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));
    reverse(all(A));

    ll tot = 0;
    for (auto f : A) tot += f;

    ll val = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        cnt++;
        val += A[i];
        if (val >= tot - val) break;
    }

    cout << m / cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}