#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x * x <= a * a + b * b) cout << "DA\n";
        else cout << "NE\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}