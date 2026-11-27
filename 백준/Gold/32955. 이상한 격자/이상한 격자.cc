#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    vector<ll> xpos, ypos;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        xpos.push_back(x);
        ypos.push_back(y);
    }
    sort(all(xpos));
    sort(all(ypos));

    vector<ll> sX(n), sY(n);
    for (int i = 0; i < n; i++) {
        sX[i] = xpos[i] + (i ? sX[i - 1] : 0);
        sY[i] = ypos[i] + (i ? sY[i - 1] : 0);
    }

    ll ansX = 1e18, ansY = 1e18;
    
    for (int i = 0; i < n; i++) {
        ll tans = 0;
        ll rv = sX[n - 1] - sX[i] - xpos[i] * (n - i - 1);
        tans += rv * a;
        ll lv = xpos[i] * (i + 1) - sX[i];
        tans += lv * b;
        ansX = min(ansX, tans);
    }
    for (int i = 0; i < n; i++) {
        ll tans = 0;
        ll rv = sY[n - 1] - sY[i] - ypos[i] * (n - i - 1);
        tans += rv * c;
        ll lv = ypos[i] * (i + 1) - sY[i];
        tans += lv * d;
        ansY = min(ansY, tans);
    }

    cout << ansX + ansY << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}