#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int INF = 10101010;
int n, k;
vector<pair<int, int>> adj[1010];
int sz[1010];
//int dp[2][1010][1010];
// 없애는 최대 간선비용합

vector<vector<int>> dp[2][1010];
vector<vector<int>> from[2][1010];

void dfs(int v, int pv = -1, int pval = 0) {
    sz[v] = 1;

    dp[0][v].push_back(vector<int>(2));
    dp[0][v][0][1] = -INF;
    dp[1][v].push_back(vector<int>(2));
    dp[1][v][0][0] = -INF;

    from[0][v].push_back(vector<int>());
    from[1][v].push_back(vector<int>());

    //cout << "Go: " << v << ' ' << pv << '\n';
    vector<int> tmp(k + 1), tmp2(k+1);
    for (int i = 0; i < adj[v].size(); i++) {
        auto& f = adj[v][i];
        if (f.first == pv) {
            adj[v].erase(adj[v].begin() + i);
            i--;
           // dp[0][v].push_back(vector<int>());
           // dp[1][v].push_back(vector<int>());
            continue;
        }


        dfs(f.first, v, f.second);
        //cout << "Done: " << f.first << ' ' << v << '\n';

        int tsz = min(k, sz[v] + sz[f.first]) + 1;
        vector<int> dp1(tsz, -INF), from1(tsz, -INF);
        vector<int> dp2(tsz, -INF), from2(tsz, -INF);
        vector<int>& pv1 = dp[0][v].back();
        vector<int>& pv2 = dp[1][v].back();
        vector<int>& sub1 = dp[0][f.first].back();
        vector<int>& sub2 = dp[1][f.first].back();

        //tmp = vector<int>(k + 1);
        for (int i = 0; i <= min(k, sz[v] - 1); i++) {
            for (int j = 0; j <= min(k, sz[f.first]) && i + j <= k; j++) {
                
                int val = pv1[i] + max(sub1[j], (j ? sub2[j] + f.second: 0));
                dp1[i + j] = max(dp1[i + j], val);
                if (dp1[i + j] == pv1[i] + sub1[j]) {
                    from1[i + j] = i * (n+1) + j << 1;
                }
                if (j && pv1[i] + sub2[j] + f.second == dp1[i + j]) {
                    from1[i+j] = (i * (n+1) + j << 1) + 1;
                }
            }
        }

        //tmp2 = vector<int>(k + 1);
        for (int i = 1; i <= min(k, sz[v]); i++) {
            for (int j = 0; j <= min(k, sz[f.first]) && i + j <= k; j++) {
                int val = pv2[i] + sub1[j] + f.second;
                dp2[i + j] = max(dp2[i + j], val);
                if (dp2[i + j] == val) {
                    from2[i + j] = i * (n +1) + j << 1;
                }
                if (j) {
                    val = pv2[i] + sub2[j];
                    dp2[i + j] = max(dp2[i + j], val);
                    if (dp2[i + j] == val) {
                        from2[i + j] = (i * (n + 1) + j << 1) + 1;
                    }
                }
            }
        }

        sz[v] += sz[f.first];
        dp[0][v].push_back(dp1);
        dp[1][v].push_back(dp2);
        from[0][v].push_back(from1);
        from[1][v].push_back(from2);
        /*cout << "---------------------DP :" << v << " + " << f.first << "\n";
        for (int i = 0; i <= min(k, sz[v]); i++) {
            cout << dp1[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i <= min(k, sz[v]); i++) {
            cout << dp2[i] << ' ';
        }
        cout << '\n';*/
    }

   /* cout << "---------------------res :" << v << "\n";
    for (int i = 0; i <= min(k, sz[v]); i++) {
        cout << dp[0][v].back()[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i <= min(k, sz[v]); i++) {
        cout << dp[1][v].back()[i] << ' ';
    }
    cout << '\n';*/
}

bool used[1010];
void backtrack(int v, int pv = -1) {

    if (v == 1) {
        pair<int, int> v1 = mp(dp[0][v].back()[k], k), v2 = { dp[1][v].back()[k], k };
        if (v1.first >= v2.first) {
            pv = v1.second << 1;
        }
        else {
            pv = (v2.second << 1) + 1;
        }
    }

    int i1 = pv & 1;
    pv >>= 1;

  //  cout << "Go: " << v << ' ' << i1 << ' ' << pv << '\n';

    if (i1) used[v] = 1;
    if (pv == 0) return;

    int ix = adj[v].size();
    while (ix > 0) {
        int val = from[i1][v][ix][pv];

        int nv = adj[v][ix - 1].first;

        //cout << "Adj: " << v << " -> " << nv << ' ' << pv << ' ' << val << '\n';
        backtrack(nv, val % (n+1<<1));
        int nx = (val >> 1) / (n + 1);
        ix--;
        pv = nx;
    }
}

void solve() {

    cin >> n >> k;

    bool modify = 0;
    if (k > n - k) {
        modify = 1;
        k = n - k;
    }

    int tot = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
        tot += c;
    }

    dfs(1);
    backtrack(1);

    int res = max(dp[0][1].back()[k], dp[1][1].back()[k]);
    cout << tot - res << '\n';

    vector<int> ans;
    for (int i = 1; i <= n; i++) if (modify ^ used[i]) ans.push_back(i);

    if (modify) k = n - k;
    assert(ans.size() == k);
    for (auto f : ans) cout << f << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}