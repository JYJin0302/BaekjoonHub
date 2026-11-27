#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

#define mp make_pair
#define all(x) x.begin(), x.end()

const int INF = 1e9;

int n;
int sA[3030];
int dp[3030];

int getDp(int x) {
    if (dp[x] != -INF) return dp[x];
    if (x == 0) return dp[x] = 0;

    int tot = sA[x];
    int res = INF;
    for (int j = 0; j < x; j++) {
        res = min(res, tot - getDp(j));
    }
    return dp[x] = res;
}

void solve() {

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    for (int i = 1; i <= n; i++) {
        sA[i] = sA[i - 1] + A[i - 1];
    }

    for (int i = 0; i <= n; i++) dp[i] = -INF;

    int aVal = getDp(n);
    int bVal = sA[n] - aVal;
    if (aVal < bVal) cout << "A\n";
    else if (aVal > bVal) cout << "B\n";
    else cout << "D\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 3;
    cin >> n;
    //cin >> t;
    while (t--) solve();
}