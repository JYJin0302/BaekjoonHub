#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << k * (m / n);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}