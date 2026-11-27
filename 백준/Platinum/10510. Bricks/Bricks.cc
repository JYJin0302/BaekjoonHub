#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}


void solve() {

    int n;
    cin >> n;

    vector<ll> A(n), B(n);
    ll cnt0 = 0, cnt1 = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        char c;
        cin >> x >> c;

        A[i] = x;
        if (c == 'W') {
            B[i] = 1;
            cnt0 += x;
        }
        else cnt1 += x;
    } 

    if (cnt0 == 0) {
        cout << cnt1 << '\n';
        return;
    }
    if (cnt1 == 0) {
        cout << cnt0 << '\n';
        return;
    }

    ll g = gcd(cnt0, cnt1);
    cnt0 /= g;
    cnt1 /= g;

    //cout << cnt0 << ' ' << cnt1 << '\n';
    int ans = 0;
    ll c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        if (B[i]) {

            if (c1 && c1 % cnt1 == 0 && c1*cnt0 / cnt1  <= c0 + A[i] && c1 * cnt0/cnt1 > c0) {
               // cout << "Ans add : " << i << '\n';
                ans++;
                c0 -= c1 * cnt0 / cnt1;
                c1 = 0;
            }
            c0 += A[i];
        }
        else {

            if (c0 && c0 % cnt0 == 0 && c0 * cnt1 / cnt0 <= c1+A[i] && c0 * cnt1 /cnt0 > c1) {
               // cout << "Ans add: " << i << '\n';
                ans++;
                c1 -= c0 * cnt1 / cnt0;
                c0 = 0;
            }
            c1 += A[i];
        }
    }
    cout << ans << '\n';

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}