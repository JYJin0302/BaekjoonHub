#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second



void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m - 1; i++) {
        cout << i << ' ' << m-1 << '\n';
    }
    for (int i = m - 1; i < n - 1; i++) cout << i << ' ' << i + 1 << '\n';

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