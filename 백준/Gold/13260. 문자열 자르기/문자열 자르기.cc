#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


vector<ll> len;
vector<ll> sLen;
ll dp[1010][1010];
ll getDp(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 0;

    ll val = sLen[r] - sLen[l] + len[l];
    ll ret = 1e15;
    for (int i = l; i < r; i++) {
        ret = min(ret, getDp(l, i) + getDp(i + 1, r));
    }
    return dp[l][r] = val + ret;
}


void solve() {
    memset(dp, -1, sizeof(dp));

    int n, m;
    cin >> n >> m;

    vector<int> A(m);
    for (auto& i : A) cin >> i;
    sort(all(A));
    int pv = 0;
    for (int i = 0; i < m; i++) {
        len.push_back(A[i] - pv);
        pv = A[i];
    }
    len.push_back(n - pv);
    sLen.push_back(len[0]);
    for (int i = 1; i < len.size(); i++) {
        sLen.push_back(sLen.back() + len[i]);
    }

    cout << getDp(0, len.size() - 1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}