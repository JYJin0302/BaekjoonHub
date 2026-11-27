#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}


void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.x >> i.y;

    set<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = A[j].x - A[i].x;
            int dy = A[j].y - A[i].y;

            if (dx == 0) {
                res.insert(mp(0, 1));
            }
            else if (dy == 0) res.insert(mp(1, 0));
            else {
                int g = gcd(abs(dx), abs(dy));
                dx /= g, dy /= g;
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }
                res.insert(mp(dx, dy));
            }
        }
    }
    cout << res.size() << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}