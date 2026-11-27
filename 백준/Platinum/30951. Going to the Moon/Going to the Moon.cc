#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ld PI = acos(-1);

struct P {
    ld x, y;
    P() : x(0), y(0) {}
    P(ld _x, ld _y) : x(_x), y(_y) {}
};

ld dist(P& a, P& b) {
    ld ans = sqrtl((a.x-b.x)*(a.x - b.x) + (a.y-b.y) * (a.y-b.y));
    return ans;
}

ld getAngle(const P& a) {    
    ld res = atan2(a.y, a.x);
    return res;
}

void solve() {

    P A, B, C;
    int r;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> r;

    A.x -= C.x;
    A.y -= C.y;
    B.x -= C.x;
    B.y -= C.y;
    C = P();

    if (dist(A, C) <= r || dist(B, C) <= r) {
        cout << dist(A, B) << '\n';
        return;
    }

    ld L = 0, R = 1;

    ld mind = min(dist(A, C), dist(B, C));
    while (L + 1e-14 < R) {
        ld m1 = (2 * L + R) / 3;
        ld m2 = (L + 2 * R) / 3;

        P p1(A.x * m1 + (1 - m1) * B.x, A.y * m1 + (1 - m1) * B.y);
        P p2(A.x * m2 + (1 - m2) * B.x, A.y * m2 + (1 - m2) * B.y);

        ld d1 = dist(p1, C);
        ld d2 = dist(p2, C);
        if (d1 <= d2) {
            R = m2;
            mind = min(mind, d1);
        }
        else {
            L = m1;
            mind = min(mind, d2);
        }
    }

    if (mind <= r) {
        cout << dist(A, B) << '\n';
        return;
    }

    // get Angle

    ld ang1 = getAngle(A);
    ld ang2 = getAngle(B);
    ld adiff = abs(ang2 - ang1);
    adiff = min(adiff, 2 * PI - adiff);

    if (abs(ang2 - ang1) != adiff) {
        if (ang1 < ang2) ang1 += 2 * PI;
        else ang2 += 2 * PI;
    }

    if (ang2 < ang1) swap(ang1, ang2);

   // assert(ang2 - ang1 == adiff);

   // assert(ang2 - ang1 <= PI + 1e-10);

    ld ans = 1e15;
    L = ang1, R = ang2;
    while (L + 1e-14 < R || ans == 1e15) {
        ld m1 = (2 * L + R) / 3;
        ld m2 = (L + 2 * R) / 3;

        P p1(r*cos(m1), r*sin(m1));
        P p2(r*cos(m2), r*sin(m2));

        ld d1 = dist(p1, A) + dist(p1, B);
        ld d2 = dist(p2, A) + dist(p2, B);

       // cout << "GO: " << m1 / PI << " = " << d1 << " | " << m2 / PI << " = " << d2 << '\n';
        if (d1 <= d2) {
            R = m2;
            ans = min(ans, d1);
        }
        else {
            L = m1;
            ans = min(ans, d2);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20);

    int t = 1;
    cin >> t;
    while (t--) solve();
}