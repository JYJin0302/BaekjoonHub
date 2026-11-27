#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair


void solve() {

    int a;
    cin >> a;

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        if (x == a) ans++;
    }
    cout << ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}