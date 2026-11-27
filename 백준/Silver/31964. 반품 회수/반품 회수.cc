#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;

    vector<pair<ll, ll>> A(n);
    for (auto& i : A) cin >> i.x;
    for (auto& i : A) cin >> i.y;

    ll curr = max(A[n - 1].x, A[n - 1].y);
    ll ans = curr + A[n - 1].x;
    for (int i = n - 2; i >= 0; i--) {
        curr = max(curr + A[i + 1].x - A[i].x, A[i].y);
        ans = max(ans, curr + A[i].x);
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