#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c, d;
    cin >> n;

    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        A[i] = a;
        B[i] = b;
        C[i] = c;
        D[i] = d;
    }

    vector<int> AB, CD;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());


    ll ans = 0;
    for (int i : AB) {
        auto k = equal_range(CD.begin(), CD.end(), -i);
        ans += k.second - k.first;
    }

    cout << ans;
}