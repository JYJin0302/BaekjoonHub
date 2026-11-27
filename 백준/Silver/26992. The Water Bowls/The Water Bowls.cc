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

    int n = 20;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> B = A;

    int ans = 22;

    int val = 1;
    B[0] ^= 1, B[1] ^= 1;
    for (int i = 1; i < n; i++) {
        if (B[i - 1] == 1) {
            B[i - 1] ^= 1;
            B[i] ^= 1;
            if (i + 1 < n) B[i + 1] ^= 1;
            val++;
        }
    }

    if (B[n - 1] == 0) ans = min(ans, val);

    val = 0;
    B = A;
    for (int i = 1; i < n; i++) {
        if (B[i - 1] == 1) {
            B[i - 1] ^= 1;
            B[i] ^= 1;
            if (i + 1 < n) B[i + 1] ^= 1;
            val++;
        }
    }

    if (B[n - 1] == 0) ans = min(ans, val);

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}