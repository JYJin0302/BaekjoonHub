#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int x, cnt = 0;
    cin >> x;
    for (int i = 0; i < 5; i++) {
        int v;
        cin >> v;
        if (v == x) cnt++;
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}