#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int col[252525];
vector<int> adj[252525];

int L[252525], R[252525];
int ord = 0;
int dp[505050];
int pos[252525];
int cpos[252525];
bool inLine[252525];
int need[252525];

void dfs(int v, int pv = -1) {
    L[v] = R[v] = ++ord;
    pos[ord] = v;
    inLine[v] = 1;

    bool tmp = 0;
    if (cpos[col[v]] != 0) {
        tmp = 1;
        int u = cpos[col[v]];
        // cout << "Call: " << u << ' ' << v << " | ";
        if (inLine[u]) {
            // cout << "P\n";
            dp[0]++; dp[R[u] + 1]--;
            //  cout << " + " << 0 << " " << L[u] << " | " << L[v] << " " << "R[v]\n";
            need[u]++;
            dp[L[v]]++; // dp[R[v] + 1]--;
            
        }
        else {
            /*cout << "S\n";
            cout << " + " << L[u] << " " << R[u] << " | " << L[v] << " " << "R[v]\n";*/
            dp[L[u]]++; dp[R[u] + 1]--;
            dp[L[v]]++; // dp[R[v] + 1]--;
        }
    }
    cpos[col[v]] = v;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        cpos[col[v]] = v;
        R[v] = ord;
        dp[R[v] + 1] += need[v];
        need[v] = 0;
    }
    R[v] = ord;
    if (tmp) need[v]--;
    dp[R[v] + 1] += need[v];
    need[v] = 0;
    inLine[v] = 0;
}



void solve() {
    int n;
    cin >> n;

    vector<int> cc(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
        cc[col[i]]++;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int r = 1;
    while (r <= n) {
        if (cc[col[r]] == 1) break;
        r++;
    }

    if (r > n) {
        cout << "0\n0\n0\n";
        return;
    }

    dfs(r);

    /*for (int j = 1; j <= ord; j++) cout << pos[j] << ' ';
    cout << '\n';
    for (int j = 1; j <= ord; j++) {
        if (j) dp[j] += dp[j - 1];
        cout << dp[j] << ' ';
    }
    cout << '\n';*/

    vector<ll> ans(3);
    for (int j = 1; j <= ord; j++) {
        dp[j] += dp[j - 1];
        if (dp[j] == 0) {
            ans[0]++;
            ans[1] += pos[j];
            ans[2] += (ll)pos[j] * pos[j];
        }
    }
    for (auto f : ans) cout << f << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}