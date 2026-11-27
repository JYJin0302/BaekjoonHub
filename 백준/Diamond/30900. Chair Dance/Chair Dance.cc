#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}
ll ex_gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

ll inv[505050];
ll tx, ty;
int pos[505050];
int tmp[505050];
int dist[505050];
void solve() {

    ll n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        pos[i] = i;
    }
    pos[0] = n;

    ll a = 1, b = 0;
    ll tot = n;
    while (q--) {

        char c;
        cin >> c;
        ll x;
        cin >> x;

        //cout << c << x << " | " << a << ' ' << b << '\n';
        if (c == '?') {
            x = (x - b + n) % n;
            ll base = n / tot;

            ll g = ex_gcd(a * base, n, tx, ty);
            //cout << x << ' ' << g << ' ' << tx << ' ' << ty << '\n';
            if (x % g != 0) {
                cout << -1 << '\n';
                continue;
            }


            if (tx < 0) {
                ll tval = n / g;
                tx = (tx % tval + tval) % tval;
            }
            ll b = x / g;
            x = tx * b % n * base % n;

            //cout << "X: " << x << ' ' << tx << ' ' << b << " : ";
            cout << pos[x] << '\n';
        }
        else if (c == '+') {
            b = (b + x) % n;
        }
        else if (c == '*') {
            if (ex_gcd(tot, x, tx, ty) == 1) {
                a = (a * x) % n;
                b = b * x % n;
            }
            else {
                // simulate
                memset(tmp, -1, sizeof(tmp));
                memset(dist, -1, sizeof(dist));

                tot = 0;
                for (int i = 0; i < n; i++) {
                    if (pos[i] == -1) continue;
                    int fi = (a * i + b) % n;
                    int ni = fi * x % n;
                    int dst = (ni - fi + n) % n;
                    if (dist[ni] == -1 || dist[ni] > dst) {
                        dist[ni] = dst;
                        tmp[ni] = pos[i];
                    }
                }

                int st = -1;
                for (int i = 0; i < n; i++) {
                    if (tmp[i] != -1) {
                        tot++;
                        if (st == -1) st = i;
                    }
                    //cout << tmp[i] << ' ';
                }
               // cout << '\n';

                for (int i = 0; i < n; i++) {
                    pos[i] = tmp[(i + st) % n];
                }
                a = 1, b = st;
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