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

    int ans = 1;
    for (int i = 0; i < n; i++) {
        int l = i - 1, r = i + 1;
        int pv = A[i];
        while (l >= 0 && r < n && A[l] == A[r] && A[l] < pv) {
            pv = A[l];
            l--, r++;
        }
        ans = max(ans, r - l - 1);
    }

    for (int i = 1; i < n; i++) {
        if (A[i] != A[i - 1]) continue;
        int l = i - 2, r = i + 1;
        int pv = A[i];
        while (l >= 0 && r < n && A[l] == A[r] && A[l] < pv) {
            pv = A[l];
            l--, r++;
        }
        ans = max(ans, r - l - 1);
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