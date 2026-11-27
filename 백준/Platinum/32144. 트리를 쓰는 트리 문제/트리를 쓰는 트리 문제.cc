#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[303030];

int dp[303030];
int dp2[303030];
int ans[303030];

void dfs(int v, int pv = -1) {

    vector<int> tmp;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);

        tmp.push_back(dp[f] + 1);
        dp2[v] = max(dp2[v], dp2[f]);
    }

    while (tmp.size() < 2) tmp.push_back(0);
    sort(all(tmp));
    reverse(all(tmp));

    dp2[v] = max(dp2[v], tmp[0] + tmp[1]);
    dp[v] = tmp[0];
}
void dfs2(int v, int pv = -1, int uVal = 0, int uV2 = 0) {

    vector<pair<int, int>> tmp, t2;
    for (auto f : adj[v]) if (f != pv) {
        tmp.push_back(mp(dp[f] + 1, f));
        t2.push_back(mp(dp2[f], f));
    }
    tmp.push_back(mp(uVal, pv));
    sort(all(tmp));
    reverse(all(tmp));
    t2.push_back(mp(uV2, pv));
    sort(all(t2));
    reverse(all(t2));

    for (auto f : adj[v]) if (f != pv) {
        vector<int> tt;
        for (auto [a, b] : tmp) {
            if (b == f) continue;
            tt.push_back(a);
            if (tt.size() == 2) break;
        }
        while (tt.size() < 2) tt.push_back(0);

        sort(all(tt));
        int nVal = tt.back() + 1;
        int nu2 = tt[0] + tt[1];
        for (auto [a, b] : t2) if (b != f) {
            nu2 = max(nu2, a);
            ans[f] = max(ans[f], a);
            break;
        }

        tt.push_back(dp2[f] + 1);
        sort(all(tt));
        ans[f] = max(ans[f], tt[1] + tt[2]);
        
        dfs2(f, v, nVal, nu2);
    }

}

void solve() {

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    dfs(1);
    dfs2(1);

    for (int i = 2; i <= n; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}