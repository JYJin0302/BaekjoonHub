#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 98765431;

struct D {
    ll m[2][2];
    D() {
        memset(m, 0, sizeof(m));
    }

    D(int n) {
        memset(m, 0, sizeof(m));
        m[0][0] = n - 2;
        m[0][1] = n - 1;
        m[1][0] = 1;
        m[1][1] = 0;
    }

    D operator*(D& o) {
        D ret;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    (ret.m[i][j] += m[i][k] * o.m[k][j] % mod) %= mod;
                }
            }
        }
        return ret;
    }

    void pf() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << m[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

void solve() {

    int n, t;
    cin >> n >> t;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    D mat, tmp(n);
    mat.m[0][0] = mat.m[1][1] = 1;
    mat.m[0][1] = mat.m[1][0] = 0;

    while (t) {
        if (t & 1) {
            mat = mat * tmp;
        }
        t >>= 1;
        tmp = tmp * tmp;

        /*cout << "RES: \n";
        mat.pf();
        cout << '\n';
        tmp.pf();
        cout << '\n';*/

    }

    ll tot = 0;
    for (auto f : A) (tot += f) %= mod;


    for (auto f : A) {
        ll s = f;
        ll o = (tot + mod - s) % mod;

        cout << (s * mat.m[1][1] % mod + o * mat.m[1][0] % mod) % mod << ' ';
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}