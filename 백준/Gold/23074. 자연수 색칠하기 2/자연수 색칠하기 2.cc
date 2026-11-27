#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;

    
    int cur = 1;
    vector<int> ans(n + 10, 1);
    for (int i = 4; i <= n; i += 2) {
        ans[i] = ans[i + 1] = ++cur;
    }

    cout << cur << '\n';
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}