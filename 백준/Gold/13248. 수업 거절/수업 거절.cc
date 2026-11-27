#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    if (c >= b) {
        cout << 0;
        return 0;
    }

    if (d == e) {
        d %= (a + b);
        if (d > a && d <= a + b - c) cout << 1;
        else cout << 0;
        return 0;
    }

    int da = d / (a + b);
    int ea = e / (a + b);
    int len = e - d;
    
    d %= (a + b);
    e %= (a + b);

    int ans = 0;
    ans += max(0, ea - da - 1) * (b - c);

    if (da == ea) {
        int l = max(d, a);
        int r = min(a + b - c, e);
        ans += max(0, r-l);
    }
    else {
        if (d < a + b - c) {
            ans += a + b - c - d;
            if (d < a) ans -= a - d;
        }

        if (e > a) {
            ans += e - a;
            if (e > a + b - c) ans -= e - (a + b - c);
        }
    }

    long double res = ans;
    res /= len;
    cout << res;
}