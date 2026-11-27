#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n; cin >> n;

    int cur = 2013;
    int dif = (n - cur) % 60;
    if (dif < 0) dif += 60;

    string ans = "F9";
    while (dif--) {
        if (ans[0] == 'L') ans[0] = 'A';
        else ans[0]++;

        if (ans[1] == '9') ans[1] = '0';
        else ans[1]++;
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