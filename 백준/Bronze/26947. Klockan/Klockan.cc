#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n;
    cin >> n;

    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {

            int ah = 0, am = 0;
            am = 60 * m;
            ah = 300 * h + 5 * m;

            int d = am - ah;
            if (d < 0) d += 3600;

            if (d == n) {
                string sh = to_string(h);
                string sm = to_string(m);
                if (sh.size() == 1) sh = '0' + sh;
                if (sm.size() == 1) sm = '0' + sm;

                cout << sh << ':' << sm << '\n';
                return;
            }

        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}