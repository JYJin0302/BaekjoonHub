#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int X[4];
int Y[4];
void solve() {

    for (int i = 0; i < 4; i++) cin >> X[i] >> Y[i];
    int xl = -1, xr = -1, yl = -1, yr = -1;
    xl = max(X[0], X[2]);
    xr = min(X[1], X[3]);
    yl = max(Y[0], Y[2]);
    yr = min(Y[1], Y[3]);

    if (xl > xr || yl > yr) {
        cout << "d\n";
        return;
    }
    int cnt = 0;    
    if (xl == xr) cnt++;
    if (yl == yr) cnt++;

    string res = "abc";
    cout << res[cnt] << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 4;
    //cin >> t;
    while (t--) solve();
}