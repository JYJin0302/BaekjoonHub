#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    vector<ll> A(n), B;
    for (auto& i : A) {
        cin >> i;
    }
    B = A;
    for (int i = 0; i < n; i++) B[i] += i * k;

    ll ans = B[n - 2] - B[n - 1], minV = B[n-1];
    for (int i = n - 3; i >= 0; i--) {
        minV = min(minV, B[i + 1]);
        ans = max(ans, B[i] - minV);
    }

    B = A;
    for (int i = 0; i < n; i++) {
        B[i] += (n - i - 1) * k;
    }
    ll ans2 = B[1] - B[0];
    minV = B[0];
    for (int i = 2; i < n; i ++) {
        minV = min(minV, B[i - 1]);
        ans2 = max(ans2, B[i] - minV);
    }

    cout << max(ans, ans2);


}