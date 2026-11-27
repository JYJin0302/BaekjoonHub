#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
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


void solve() {

    double a, h, b;
    cin >> a >> b >> h;
    if (a > b) swap(a, b);
    
    if (a == b){
        cout << -1;
        return;
    }

    h = sqrt(h * h + (b - a) * (b - a));
    double r = a * h / (b - a);

    double PI = acos(-1);

    cout << setprecision(10);
    cout << (r + h) * (r + h) * PI - r * r * PI;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}