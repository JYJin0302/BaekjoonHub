#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int L = a + b + c + d + e;
    int R = a * 4 + b * 6 + c * 8 + d * 12 + e * 20;

    vector<int> res;
    int p = 0;
    while (L <= R) {
        if (p) res.push_back(L++);
        else res.push_back(R--);
        p ^= 1;
    }
    reverse(all(res));
    for (auto f : res) cout << f << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}