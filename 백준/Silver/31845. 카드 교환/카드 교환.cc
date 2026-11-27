#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (auto& i : A) cin >> i;
    sort(A.rbegin(), A.rend());

    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r && m) {
        m--;
        ans += max(0, A[l++]);
        r--;
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