#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {

    string s;
    cin >> s;

    int val = 0, ans = 0;
    bool ok = 0;
    for (auto f : s) {
        if (f == 'L') {
            val = (val + 3) % 4;
        }
        else {
            val = (val + 1) % 4;
            if (ok && val == 0) ans++;
            if (val == 1) ok = 1;
        }
        if (val == 0) ok = 0;

    }
    cout << ans;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}