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

    int ans = 0;
    int pv = -1, len = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] >= pv) len++;
        else {
            ans = max(ans, len);
            len = 1;
        }
        pv = A[i];
    }
    ans = max(ans, len);

    pv = -1, len = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] <= pv) len++;
        else {
            ans = max(ans, len);
            len = 1;
        }
        pv = A[i];
    }
    ans = max(ans, len);

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}