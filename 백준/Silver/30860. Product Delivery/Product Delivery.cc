#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int n;
int L[1001010], R[1001010];

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
    }

    int pv = R[n - 1];
    int ans = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (L[i] > pv) {
            ans++;
            pv = R[i];
        }
        pv = min(pv, R[i]);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
