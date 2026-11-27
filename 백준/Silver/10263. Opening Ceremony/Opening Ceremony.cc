#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    sort(A.begin(), A.end());

    int ans = n;
    for (int i = 0; i < n; i++) {
        ans = min(ans, A[i] + n - 1 - i);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
