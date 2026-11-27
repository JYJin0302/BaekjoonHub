#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.x >> i.y;
    A.push_back(A[0]);

    bool ok = 0;

    vector<pair<int, int>> route;
    for (int i = 1; i <= n; i++) {
        int a = A[i - 1].y;
        int b = A[i].y;
        if (a > b) swap(a, b);

        if (b == a + 180) ok = 1;
        else if (b < a + 180) {
            route.push_back(mp(a, b));
        }
        else {
            route.push_back(mp(b, 180));
            route.push_back(mp(-180, a));
        }
    }

    if (ok) {
        cout << "yes\n";
        return;
    }
    sort(all(route));

    int pv = -180;
    for (auto& [a, b] : route) {
        if (a > pv) {
            cout << "no " << -0.5 + a;
            return;
        }
        pv = max(pv, b);
    }
    if (pv != 180) {
        cout << "no " << 179.5;
    }
    else cout << "yes";


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}