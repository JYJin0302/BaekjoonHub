#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> A(n + 1);

    const ll mod = 1e9;

    A[0] = 1;
    for (int i = 1; i <= n; i*=2) {
        for (int j = i; j <= n; j++) {
            A[j] += A[j - i];
            A[j] %= mod;
        }
    }
    cout << A[n];

}