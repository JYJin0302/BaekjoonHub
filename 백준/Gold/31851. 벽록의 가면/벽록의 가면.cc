#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int n;
vector<pair<ll, ll>> A;

int ans = 0;
pair<ll, ll> cur[4], tmp[4];

ll tx = 0, ty = 0;
bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    p1.x -= tx, p1.y -= ty;
    p2.x -= tx, p2.y -= ty;
    return p1.x * p2.y - p2.x * p1.y > 0;
}

ll ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
    ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    return res;
}

void chk() {
    for (int i = 0; i < 4; i++) tmp[i] = cur[i];
    sort(tmp, tmp + 4);
    tx = tmp[0].x, ty = tmp[0].y;
    sort(tmp + 1, tmp + 4, cmp);

    for (int i = 0; i < 4; i++) {
        int p1 = (i + 2) % 4;
        int p2 = (i + 3) % 4;
        if (ccw(tmp[p1], tmp[p2], tmp[i]) <= 0) return;
    }
    ans++;
}


void choose(int ix, int pre = 0) {
    if (ix == 4) {
        chk();
        return;
    }
    for (int i = pre; i < n; i++) {
        cur[ix] = A[i];
        choose(ix + 1, i + 1);
    }
}

void solve() {

    cin >> n;
    A = vector<pair<ll, ll>>(n);
    for (auto& i : A) cin >> i.x >> i.y;
    choose(0);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}