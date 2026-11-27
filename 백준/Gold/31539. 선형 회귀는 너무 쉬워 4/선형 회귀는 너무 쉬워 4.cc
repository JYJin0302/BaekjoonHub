#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;


void solve() {

    int n, b;
    cin >> n >> b;

    vector<pair<ld, ld>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;

    
    ld l = -1e16, r = 1e16;
    while (r - l > 1e-8) {
        ld m1 = (2 * l + r) / 3;
        ld m2 = (l + 2 * r) / 3;

        ld val1 = 0, val2 = 0;
        for (int i = 0; i < n; i++) {
            // y = m1 * x + b
            ld dy = m1 * A[i].first + b - A[i].second;
            val1 += dy * dy * dy * dy;

            dy = m2 * A[i].first + b - A[i].second;
            val2 += dy * dy * dy * dy;
        }

        if (val1 < val2) r = m2;
        else l = m1;
    }
    cout << setprecision(10);
    cout << l << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}