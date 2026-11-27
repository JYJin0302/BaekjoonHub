#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[40404], adj2[40404];

int dp[40404];
int cnt1[40404], cnt2[40404];
void dfs(int v, int pv = -1) {
    dp[v] = 0;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        dp[v] = max(dp[v], dp[f] + 1);
    }
}

void dfs2(int v, int pv = -1, int pval = 0) {
    vector<pair<int, int>> res;
    res.push_back(mp(-1, v));
    if (pv != -1) res.push_back(mp(pval, pv));

    for (auto f : adj[v])if (f != pv) {
        res.push_back(mp(dp[f], f));
    }
    sort(all(res));
    reverse(all(res));

    int dep = dp[v];
    if (!res.empty()) dep = max(dep, res[0].x + 1);
    cnt1[dep]++;

    for (auto f : adj[v])if (f != pv) {
        for (auto [a, b] : res) {
            if (b == f) continue;
            dfs2(f, v, a + 1);
            break;
        }
    }
}

ll S1[40404], S2[40404];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < m - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }

    dfs(1);
    dfs2(1);

    swap(adj, adj2);
    swap(cnt1, cnt2);
    dfs(1);
    dfs2(1);
    swap(cnt1, cnt2);

    int D1 = 0, D2 = 0;
    for (int i = 0; i < n; i++) {
        if (cnt1[i]) D1 = i;
    }
    for (int i = 0; i < m; i++) {
        if (cnt2[i]) D2 = i;
    }


    /*for (int i = 0; i < n; i++) cout << cnt1[i] << ' ';
    cout << '\n';
    for (int i = 0; i < m; i++) cout << cnt2[i] << ' ';
    cout << '\n';*/
    for (int i = D2; i >= 0; i--) {
        S2[i] = 1ll * i * cnt2[i] + (i != D2 ? S2[i + 1] : 0);
        cnt2[i] += cnt2[i + 1];
    }

    int maxD = max(D1, D2);
    ll ans = 0;
    for (int i = 0; i <= D1; i++) {
        if (!cnt1[i]) continue;

        int dif = maxD - i;
        ans += (S2[dif] + 1ll * cnt2[dif] * (i + 1)) * cnt1[i];
        ans += 1ll * (m - cnt2[dif]) * maxD * cnt1[i];
    }

    cout << fixed << setprecision(3);
    cout << 1.0 * ans / n / m;

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}