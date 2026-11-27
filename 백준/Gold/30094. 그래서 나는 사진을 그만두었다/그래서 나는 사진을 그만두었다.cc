#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct D {
    ll x, y;
    int idx;

    bool operator<(D& o) {
        return y - x < o.y - o.x;
    }
};


const int mod = 998244353;
ll f[101010];


void solve() {

    int n;
    cin >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;

    vector<D> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
        A[i].idx = i + 1;
    }
    sort(all(A));

    ll cnt = 1;
    int ix = 0;
    while (ix < n) {
        int nx = ix;
        while (nx < n && A[nx].y - A[nx].x == A[ix].y - A[ix].x) nx++;
        int len = nx - ix;
        cnt = cnt * f[len] % mod;
        ix = nx;
    }
    ll v1 = 0;
    for (int i = 0; i < n; i++) {
        v1 += A[i].x * i + A[i].y * (n - 1 - i);
    }
    cout << v1 << ' '<< cnt <<'\n';
    for (int i = 0; i < n; i++) cout << A[i].idx << ' ';
    cout << '\n';

    reverse(all(A)); 
    ll v2 = 0;
    for (int i = 0; i < n; i++) {
        v2 += A[i].x * i + A[i].y * (n - 1 - i);
    }

    cout << v2 << ' ' << cnt << '\n';
    for (int i = 0; i < n; i++) cout << A[i].idx << ' ';
    cout << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}