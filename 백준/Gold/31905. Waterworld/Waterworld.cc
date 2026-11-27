#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, m;
    cin >> n >> m;

    ll ans = 0;
    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        ans += x;
    }

    cout << fixed << setprecision(10);
    cout << 1.0 * ans / (n * m) << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) solve();
}