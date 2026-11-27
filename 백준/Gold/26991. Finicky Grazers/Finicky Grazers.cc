#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 1e13;

void solve() {

    int n, l;
    cin >> n >> l;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int d = l / (n - 1);
    int c1 = l % (n - 1);
    int c0 = n - 1 - c1;

    vector<ll> dp(n, INF), tmp(n, INF);
    dp[0] = A[0];
    for (int i = 1; i < n; i++) {
        tmp = vector<ll>(n, INF);
        for (int j = 0; j < i; j++) {
            int np = i * d + j;
            tmp[j] = min(tmp[j], dp[j] + abs(np - A[i]));
            tmp[j + 1] = min(tmp[j + 1], dp[j] + abs(np + 1 - A[i]));
        }

        swap(tmp, dp);
    }
    cout << dp[c1];
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}