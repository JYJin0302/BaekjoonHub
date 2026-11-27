#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

ld dist(pair<ld, ld>& p1, pair<ld, ld>& p2) {
    return sqrtl((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void solve() {

    int n;
    cin >> n;
    vector<pair<ld, ld>> A(n);
    for (auto& i : A) cin >> i.x >> i.y;

    sort(all(A));

    int ix = 0;

    pair<ld, int> d, u;
    while (ix < n) {
        int nx = ix;
        while (nx < n && A[nx].x == A[ix].x) nx++;
        if (ix == 0) {
            d = mp(0, 0);
            u = mp(0, nx - 1);
        }
        else {
            pair<ld, int> nd, nu;
            nd = mp(max(u.x + dist(A[u.y], A[ix]), d.x + dist(A[d.y], A[ix])), ix);
            nu = mp(max(d.x + dist(A[d.y], A[nx - 1]), u.x + dist(A[u.y], A[nx-1])), nx - 1);
            d = nd;
            u = nu;
        }
        ix = nx;
    }

    cout << setprecision(15);
    cout << max(d.x, u.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}