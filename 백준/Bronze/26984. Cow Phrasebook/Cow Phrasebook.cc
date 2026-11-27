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
    cin.ignore();
    vector<string> A(n), B(m);
    for (int i = 0; i < n; i++) {
        getline(cin, A[i]);
    }
    for (int i = 0; i < m; i++) {
        getline(cin, B[i]);
    }
    sort(all(A));

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int len = B[i].size();

        auto ix = lower_bound(all(A), B[i]) - A.begin();

        if (ix == n) {}
        else {
            bool ok = 1;
            if (A[ix].size() < len) ok = 0;
            else {
                for (int j = 0; j < len; j++) {
                    if (B[i][j] != A[ix][j]) ok = 0;
                }
            }
            ans += ok;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}