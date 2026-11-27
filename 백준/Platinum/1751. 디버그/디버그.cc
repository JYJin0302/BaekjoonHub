#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

char G[303][303];


int n, m;
const int p1 = 100003;
const int p2 = 998244353;
bool inGrid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}


ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

ll S[303][303];
ll rS[303][303];

bool chk(int x1, int y1, int x2, int y2) {
    
    ll t1 = (x1 - 1) * m + y1 - 1; t1 = fastPow(p1, t1, p2);
    ll v1 = S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
    v1 = ((v1 % p2) + p2) % p2;
    v1 = v1 * fastPow(t1, p2 - 2, p2) % p2;

    x1 = n - x1 + 1;
    x2 = n - x2 + 1;
    y1 = m - y1 + 1;
    y2 = m - y2 + 1;
    swap(x1, x2); swap(y1, y2);
    ll t2 = (x1 - 1) * m + y1 - 1; t2 = fastPow(p1, t2, p2);

    ll v2 = rS[x2][y2] - rS[x1 - 1][y2] - rS[x2][y1 - 1] + rS[x1 - 1][y1 - 1];
    v2 = ((v2 % p2) + p2) % p2;
    v2 = v2 * fastPow(t2, p2 - 2, p2) % p2;
    return v1 == v2;
}



void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int v = (i - 1)* m + j - 1;
            if(G[i][j] == '1') S[i][j] = fastPow(p1, v, p2);
            S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + p2;
            S[i][j] %= p2;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int v = (i - 1) * m + j - 1;
            if (G[n-i+1][m-j+1] == '1') rS[i][j] = fastPow(p1, v, p2);
            rS[i][j] += rS[i - 1][j] + rS[i][j - 1] - rS[i - 1][j - 1] + p2;
            rS[i][j] %= p2;
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            int res = 1;
            while (inGrid(i-res, j-res) &&inGrid(i+res, j+ res)) {
                if (chk(i - res, j - res, i + res, j + res)) {
                    res++;
                }
                else break;
            }
            ans = max(ans, res * 2 - 1);
            res = 0;
            while (inGrid(i - res, j - res) && inGrid(i + 1 + res, j + 1 + res)) {
                if (chk(i - res, j - res, i + 1 + res, j + 1 + res)) {
                    res++;
                }
                else break;
            }
            ans = max(ans, res * 2);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}