#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
#define mp make_pair


ld px1, py1, px2, py2, px3, py3;
const ld eps = 1e-3;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld getVal2(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {

    ld x_min, x_max, y_min, y_max;
    x_min = min({ x1, x2, x3 });
    x_max = max({ x1, x2, x3 });
    y_min = min({ y1, y2, y3 });
    y_max = max({ y1, y2, y3 });

    ld ans = 1e10;
    bool ok = 1;
    while (x_min + eps < x_max || ok) {
        ok = 0;
        ld dx = (x_max - x_min) / 3;

        ld ty_min = y_min, ty_max = y_max;

        ld mid1 = x_min + dx;
        ld mid2 = mid1 + dx;

        ld res1 = 1e10;
        ld currx = mid1; 
        bool tmp = 1;
        while (ty_min + eps < ty_max || tmp) {
            tmp = 0;

            ld dy = (ty_max - ty_min) / 3;

            ld midy1 = ty_min + dy;
            ld midy2 = midy1 + dy;

            ld val1 = dist(x1, y1, currx, midy1) + dist(x2, y2, currx, midy1) + dist(x3, y3, currx, midy1);
            ld val2 = dist(x1, y1, currx, midy2) + dist(x2, y2, currx, midy2) + dist(x3, y3, currx, midy2);

            if (val1 <= val2) ty_max = midy2;
            else ty_min = midy1;

            res1 = min({ res1, val1, val2 });
        }

        ld res2 = 1e10;
        currx = mid2; ty_min = y_min, ty_max = y_max;
        tmp = 1;
        while (ty_min + eps < ty_max || tmp) {
            tmp = 0;

            ld dy = (ty_max - ty_min) / 3;

            ld midy1 = ty_min + dy;
            ld midy2 = midy1 + dy;

            ld val1 = dist(x1, y1, currx, midy1) + dist(x2, y2, currx, midy1) + dist(x3, y3, currx, midy1);
            ld val2 = dist(x1, y1, currx, midy2) + dist(x2, y2, currx, midy2) + dist(x3, y3, currx, midy2);

            if (val1 <= val2) ty_max = midy2;
            else ty_min = midy1;

            res2 = min({ res2, val1, val2 });
        }

        if (res1 <= res2) x_max = mid2;
        else x_min = mid1;

        ans = min({ ans, res2, res1 });
    }

    return ans;
}

ld getVal(ld x, ld y) {
    ld res = 0.0;
    res = max(res, getVal2(px1, py1, px2, py2, x, y));
    res = max(res, getVal2(px1, py1, px3, py3, x, y));
    res = max(res, getVal2(px3, py3, px2, py2, x, y));
    return res;
}

void solve() {

    cin >> px1 >> py1 >> px2 >> py2 >> px3 >> py3;

    ld x_min, x_max, y_min, y_max;
    x_min = min({ px1, px2, px3 });
    x_max = max({ px1, px2, px3 });
    y_min = min({ py1, py2, py3 });
    y_max = max({ py1, py2, py3 });
   

    ld ans = 1e10;

    bool ok = 1;

    while (x_min + eps < x_max || ok) {
        ok = 0;
        ld dx = (x_max - x_min) / 3;

       // cout << "GO: " << x_min << ' ' << x_max << '\n';

        ld ty_min = y_min, ty_max = y_max;

        ld mid1 = x_min + dx;
        ld mid2 = mid1 + dx;

        ld currx = mid1;
        ld res1 = 1e10;

       // cout << "test1: " << mid1 << '\n';

        bool tmp = 1;
        while (ty_min + eps < ty_max || tmp) {
            tmp = 0;

            ld dy = (ty_max - ty_min) / 3;
            //cout << "----go : " << ty_min << ' ' << ty_max << '\n';

            ld midy1 = ty_min + dy;
            ld midy2 = midy1 + dy;

            ld val1 = getVal(currx, midy1);
            ld val2 = getVal(currx, midy2);
            
            //cout << "----res: " << val1 << ' ' << val2 << '\n';
            if (val1 <= val2) ty_max = midy2;
            else ty_min = midy1;
            res1 = min({ res1, val1, val2 });
        }

       // cout << "test2: " << mid2 << '\n';

        ld res2 = 1e10;
        currx = mid2; ty_min = y_min, ty_max = y_max;
        tmp = 1;
        while (ty_min + eps < ty_max || tmp) {
            tmp = 0;

            ld dy = (ty_max - ty_min) / 3;

           // cout << "----go : " << ty_min << ' ' << ty_max << '\n';
            ld midy1 = ty_min + dy;
            ld midy2 = midy1 + dy;

            ld val1 = getVal(currx, midy1);
            ld val2 = getVal(currx, midy2);

           // cout << "----res: " << val1 << ' ' << val2 << '\n';
            if (val1 <= val2) ty_max = midy2;
            else ty_min = midy1;
            res2 = min({ res2, val1, val2 });
        }

        if (res1 <= res2) x_max = mid2;
        else x_min = mid1;

       // cout << "RES: " << res1 << ' ' << res2 << '\n';

        ans = min({ ans, res2, res1 });
    }

    cout << ans;


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}