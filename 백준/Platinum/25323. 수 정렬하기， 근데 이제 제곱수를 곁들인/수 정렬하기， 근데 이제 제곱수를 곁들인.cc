#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    for (auto& i : A) cin >> i;
    B = A;
    sort(B.begin(), B.end());

    bool ok = 1;
    for (int i = 0; i < n; i++) {
        ll g = gcd(A[i], B[i]);
        A[i] /= g;
        B[i] /= g;

        ll tv = sqrtl(A[i]);
        if (tv * tv != A[i]) ok = 0;
        tv = sqrtl(B[i]);
        if (tv * tv != B[i]) ok = 0;

    }

    if (ok) cout << "YES";
    else cout << "NO";
}