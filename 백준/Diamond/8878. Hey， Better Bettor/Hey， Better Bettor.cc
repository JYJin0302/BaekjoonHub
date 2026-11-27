#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair


ld pw[2000202];
ld x, p;
ld solve(ld x, ld p) {
    ld res = 0;
    x /= 100;
    p /= 100;
    x = 1 - x;
    if (p == 0) return 0;

    ld f = (1 - p) / p;

    pw[0] = 1;
    for (int i = 1; i <= 2000000; i++) pw[i] = pw[i - 1] * f;
    
    for (register int low = 1; low <= 1000000; low++) {
        ld tans = 0;
        for (register int high = 1; high+low <= 2000000; high++) {

            ld b = 1 - pw[low + high];
            ld win = 1 - pw[low];
            win /= b;
            ld lose = 1 - win;

            ld tval = high * win - lose * x * low;
            if (tval < 0 || tval < tans - 1e-5) break;
            tans = max(tans, tval);
            res = max(res, tans);
        }
        if (tans < res - 1e-5) break;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(15) << fixed;
    cin >> x >> p;
    ld ans = solve(x, p);
    cout << ans;
    return 0;
}
