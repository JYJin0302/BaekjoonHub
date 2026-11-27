#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const string P1 = "kidw0124";
const string P2 = "eoaud0108";


void solve() {

    ll n, p;
    cin >> n >> p;

    if (p == 0) {
        if (n == 1) {
            cout << P1 << '\n';
            return;
        }
        if (n == 2) {
            cout << P2 << '\n';
            return;
        }
        ll t = n / 2;
        if (t % 2 == 0) {
            cout << P2 << '\n';
            return;
        }
        else cout << P1 << '\n';
        return;
    }
    else {
        if (n == 2) {
            cout << P1 << '\n';
            return;
        }
        if (n == 3) {
            cout << P2 << '\n';
            return;
        }

        ll t = n / 2;
        if (t % 2 == 0) {
            if (n % 2 == 0) {
                cout << P1 << '\n';
            }
            else {
                cout << P2 << '\n';
            }
        }
        else {
            if (n % 2 == 0) {
                cout << P2 << '\n';
            }
            else {
                cout << P1 << '\n';
            }
        }

    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}