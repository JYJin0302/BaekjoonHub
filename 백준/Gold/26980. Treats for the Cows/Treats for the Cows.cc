#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;
int A[2020];
int dp[2020][2020];

int getDp(int l, int r) {
    if (dp[l][r] != 0) return dp[l][r];
    int age = n - (r - l);
    if (l == r) return dp[l][r] = age * A[l];
    return dp[l][r] = max(getDp(l+1, r) + A[l] * age, getDp(l, r-1) + A[r] * age);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << getDp(0, n - 1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}