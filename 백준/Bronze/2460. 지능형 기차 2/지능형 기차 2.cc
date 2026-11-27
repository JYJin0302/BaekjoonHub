#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n = 10;
    int val = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        val += b - a;
        mx = max(mx, val);
    }
    cout << mx;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}