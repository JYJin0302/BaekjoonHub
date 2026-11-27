#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct P {
    ld x, y;

    P() {
        x = y = 0;
    }
};

ld dist(P p1, P p2) {
    return sqrtl((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    P s, e;
    cin >> s.x >> s.y >> e.x >> e.y;

    P c1, c2;
    ld r1, r2;
    cin >> c1.x >> c1.y >> r1 >> c2.x >> c2.y >> r2;
    
    ld ans = 0;

    ld d1 = dist(s, c2);
    ans += sqrtl(d1 * d1 - r2 * r2);

    ld d2 = dist(e, c2);
    ans += sqrtl(d2 * d2 - r2 * r2);

    ld d3 = dist(s, e);
    ld ang1 = acos((d1 * d1 + d2 * d2 - d3 * d3) / (2 * d1 * d2));

    ld ang2 = acos(r2 / d1);
    ld ang3 = acos(r2 / d2);

    ld tmp = ang1 - ang2 - ang3;
    ld tmp2 = 2 *acos(-1) - tmp - 2 * ang2 - 2 * ang3;

    ans += min(tmp, tmp2) * r2;
    cout << ans;

}