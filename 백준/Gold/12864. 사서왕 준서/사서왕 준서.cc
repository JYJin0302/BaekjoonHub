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
    vector<ld> A(n);
    for (auto& i : A) cin >> i;

    int tot = 0;
    vector<int> C(n);
    for (auto& i : C) {
        cin >> i;
        tot += i;
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) if (A[j] <= A[i] + 1e-9) mx = max(mx, dp[j]);
        dp[i] = mx + C[i];
    }
    cout << tot - *max_element(all(dp));

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}