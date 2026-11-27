#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
#define mp make_pair

int n;
pair<int, int> A[101];
const ld eps = 1e-6;

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ld getVal(ld x, ld y) {

    ld res = 1e10;
    for (int i = 0; i < n; i++) {

        int ni = (i + 1) % n;

        //cout << "Line: " << i << " : ";
        int a = A[ni].second - A[i].second;
        int b = A[i].first - A[ni].first;
        int c = a * A[i].first + b * A[i].second;
        c *= -1;

        int g = gcd(gcd(abs(a), abs(b)), abs(c));
        a /= g;
        b /= g;
        c /= g;

        ld tans = sqrt(a * a + b * b);
        tans = abs(a * x + b * y + c) / tans;

        res = min(res, tans);
    }
    return res;

}

pair<ld, ld> getRange(ld x) {

    vector<ld> tmp;

    for (int i = 0; i < n; i++) {

        int ni = (i + 1) % n;

        if (min(A[i].first, A[ni].first) > x) continue;
        if (max(A[i].first, A[ni].first) < x) continue;

        //cout << "Line: " << i << " : ";
        int a = A[ni].second - A[i].second;
        int b = A[i].first - A[ni].first;
        int c = a * A[i].first + b * A[i].second;
        c *= -1;

        int g = gcd(gcd(abs(a), abs(b)), abs(c));
        a /= g;
        b /= g;
        c /= g;

        if (b == 0) {
            tmp.push_back(A[ni].second);
            tmp.push_back(A[i].second);
        }
        else {
            tmp.push_back(-((ld)c + (ld)a * x) / (ld)b);
        }
    }

    if (tmp.empty()) return mp(1, -1);

    ld v1, v2;
    v1 = *min_element(tmp.begin(), tmp.end());
    v2 = *max_element(tmp.begin(), tmp.end());
    return mp(v1, v2);
}

void solve() {


    ld x_min = 10101, x_max = -1, y_min = 0, y_max = 10000;
    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
        x_min = min(x_min, (ld)A[i].first);
        x_max = max(x_max, (ld)A[i].first);
    }

    ld ans = 0;

    while (x_min + eps < x_max) {
        ld dx = (x_max - x_min) / 3;

       // cout << "GO: " << x_min << ' ' << x_max << '\n';

        ld ty_min, ty_max;
        ld mid1 = x_min + dx;
        ld mid2 = mid1 + dx;

        ld currx = mid1;
        ld res1 = 0;

       // cout << "test1: " << mid1 << ' ';

        tie(ty_min, ty_max) = getRange(currx);
       // cout << "range: " << ty_min << ' ' << ty_max << '\n';

        while (ty_min + eps < ty_max) {

            ld dy = (ty_max - ty_min) / 3;
           // cout << "----go : " << ty_min << ' ' << ty_max << '\n';

            ld midy1 = ty_min + dy;
            ld midy2 = midy1 + dy;

            ld val1 = getVal(currx, midy1);
            ld val2 = getVal(currx, midy2);
            
           // cout << "----res: " << val1 << ' ' << val2 << '\n';
            if (val1 >= val2) ty_max = midy2;
            else ty_min = midy1;
            res1 = max({ res1, val1, val2 });
        }

       // cout << "test2: " << mid2 << ' ';
        
        ld res2 = 0;
        currx = mid2;
        tie(ty_min, ty_max) = getRange(currx);

       // cout << "RAnge: " << ty_min << ' ' << ty_max << '\n';

        while (ty_min + eps < ty_max) {

            ld dy = (ty_max - ty_min) / 3;

           // cout << "----go : " << ty_min << ' ' << ty_max << '\n';
            ld midy1 = ty_min + dy;
            ld midy2 = midy1 + dy;

            ld val1 = getVal(currx, midy1);
            ld val2 = getVal(currx, midy2);

           // cout << "----res: " << val1 << ' ' << val2 << '\n';
            if (val1 >= val2) ty_max = midy2;
            else ty_min = midy1;
            res2 = max({ res2, val1, val2 });
        }

        if (res1 >= res2) x_max = mid2;
        else x_min = mid1;

       // cout << "RES: " << res1 << ' ' << res2 << '\n';

        ans = max({ ans, res2, res1 });
    }

    cout << ans << '\n';


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    cin >> n;
    while (n) {
        solve();
        cin >> n;
    }

}