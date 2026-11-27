#include <bits/stdc++.h>
using namespace std;

int main() {

    double x, y, d, t;
    cin >> x >> y >> d >> t;

    double dist = sqrt(x * x + y * y);
    
    cout << setprecision(17) << fixed;
    
    double ans = dist;
    if (dist <= d) {
        ans = min({ ans, t + d - dist, 2 * t });
    }
    else {
        ans = min({ans, ceil(dist / d) * t, floor(dist / d) * t + dist - floor(dist / d) * d});
    }

    cout << ans;
}