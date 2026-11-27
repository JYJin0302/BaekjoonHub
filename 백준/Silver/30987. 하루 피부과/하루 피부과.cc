#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    ll x1, x2;
    ll a, b, c, d, e;
    cin >> x1 >> x2 >> a >> b >> c >> d >> e;

    a /= 3;
    b /= 2;
    d /= 2;

    
    ll v1 = a * (x2 * x2 * x2 - x1 * x1 * x1) + b * (x2 * x2 - x1 * x1) + c * (x2 - x1);
    ll v2 = d * (x2 * x2 - x1 * x1) + e * (x2 - x1);
    cout << v1 - v2;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
