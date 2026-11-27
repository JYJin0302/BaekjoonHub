#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

map<ll, ll> dp;
ll n, k;

ll goSolve(ll v) {
    if (dp[v]) return dp[v];

    if (v > k && (v - k) % 2 == 0) {
        return dp[v] = goSolve((v - k) / 2) + goSolve((v + k) / 2);
    }
    return dp[v] = 1;
}

void solve() {

    cin >> n >> k;

    cout << goSolve(n);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}