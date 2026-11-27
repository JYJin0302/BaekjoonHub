#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
void solve() {
 
    int n;
    cin >> n;
 
    vector<int> A(n);
    for (auto& i : A) cin >> i;
 
    if (n == 1) {
        cout << 1;
        return;
    }
 
    for (int i = 1; i < n; i++) {
        if (n % i) continue;
 
        int ix = 0;
        int val = -1;
        bool ok = 1;
        while (ix < n) {
            int mn = A[ix];
            int mx = A[ix];
 
            for (int j = 0; j < i; j++) {
                mn = min(mn, A[ix + j]);
                mx = max(mx, A[ix + j]);
            }
 
            if (val == -1 || val == mn + mx) val = mn + mx;
            else {
                ok = 0;
                break;
            }
            ix += i;
        }
 
        if (ok) {
            cout << 1;
            return;
        }
    }
    cout << 0;
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
