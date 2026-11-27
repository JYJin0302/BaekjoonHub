#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> A(n), B(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    ll ans = 0;
    for (int i = 0; i < n; i++) {

        ll tans = 1e9;
        for(int j = 0; j < n; j++)tans = min(tans, abs(A[i] - B[j]));
        ans = max(ans, tans);
    }
    cout << ans;
}