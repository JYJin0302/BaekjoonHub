#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[303030];
int dfsn[303030];
int dep[303030];
int spt[20][303030];
int p[303030];
int dp[303030];

void dfs(int v, int pv = -1) {
    static int ord = 0;
    dfsn[v] = ++ord;
    for (auto f : adj[v]) if (f != pv) {
        spt[0][f] = v;
        dep[f] = dep[v] + 1;
        dfs(f, v);
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int dif = dep[v] - dep[u];
    for (int i = 0; i < 20; i++) {
        if (dif & (1 << i)) v = spt[i][v];
    }

    for (int i = 19; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
        }
    }
    if (u != v) u = spt[0][u];
    return u;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    while (q--) {
        int k;
        cin >> k;

        vector<int> A(k);
        for (auto& i : A) cin >> i;
        
        if(k == 1){
            cout << 0 << '\n';
            continue;
        }
        vector<int> tmp = A;
        sort(all(A), [](int& a, int& b) { return dfsn[a] < dfsn[b]; });
        for (int i = 1; i < k; i++) {
            A.push_back(lca(A[i], A[i - 1]));
        }
        sort(all(A), [](int& a, int& b) { return dfsn[a] < dfsn[b]; });
        A.erase(unique(all(A)), A.end());

        k = A.size();
        for (int i = 1; i < k; i++) {
            int l = lca(A[i - 1], A[i]);
            p[A[i]] = l;
        }

        for (auto f : A) dp[f] = 0;
        for (auto f : tmp) dp[f] = 1;
        int tot = tmp.size();

        int res = 0;
        sort(all(A), [](int& a, int& b) { return dep[a] > dep[b]; });
        for (auto f : A) {
            dp[p[f]] += dp[f];
            if (dp[p[f]] * 2 >= tot) {
                res = p[f];
                break;
            }
        }
        ll ans = 0;
        for (auto f : tmp) ans += dep[f] + dep[res] - 2 * dep[lca(f, res)];
        cout << ans << '\n';
    }

}