#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

    ll n, l, w, h;
    cin >> n >> l >> w >> h;
    cout << fixed << setprecision(20);

    vector<ll> A = { l, w, h };
    double ans = 0;

    double L = 0, R = 1e9;

    int cnt = 65;
    while (cnt--) {

        double mid = (L + R) / 2;

        ll a = floor(l / mid) * floor(w / mid) * floor(h / mid);

        if (a >= n) {
            L = mid;
        }
        else R = mid;
    }

    cout << (L + R) / 2;
}