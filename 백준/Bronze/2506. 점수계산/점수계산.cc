#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int ans = 0, pv = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) ans += ++pv;
        else pv = 0;
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