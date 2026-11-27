#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second


void solve() {

    ld T_f, V_f, H_f;
    ld T_d, V_d, H_d;

    cin >> T_f >> V_f >> H_f >> T_d >> V_d >> H_d;


    ld l = T_d, r = 1e16;

    ld t1 = sqrtl(2 * H_d / 3);
    ld t2 = sqrtl(2 * H_f);

    ld ans = 1e16;
    while (l + 1e-9 < r) {

        ld mid = (l + r) / 2;

        ld pos_d, height_d;
        ld pos_f, height_f;

        pos_d = (mid - T_d) * V_d;
        if (mid >= T_d + t1) {
            height_d = H_d;
        }
        else {
            height_d = 0.5 * (3 * t1 + 3 * t1 - 3 * (mid - T_d)) * (mid - T_d);
        }

        if (mid >= t2 + T_f) {
            // at ground
            pos_f = t2 * V_f;
            height_f = 0;
        }
        else {
            pos_f = (mid - T_f) * V_f;
            height_f = H_f - 0.5 * (mid - T_f) * (mid - T_f);
        }

        if (pos_d >= pos_f && height_d >= height_f) {
            // can catch
            ans = mid + pos_f / V_d;
            r = mid;
        }
        else l = mid;
    }

    cout << fixed << setprecision(10);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    solve();
    return 0;
}
