#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define x first
#define y second

vector<int> adj[202020], nadj[202020];
vector<int> cadj[202020];
int n, m;
int dep[202020];
int d2[202020];
int spt[20][202020];

set<pair<int, int>> minV[202020];
int lca(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    int dif = dep[v] - dep[u];
    for(int i = 0; i < 20 ;i++){
        if (dif & (1 << i)){
            v = spt[i][v];
        }
    }

    for(int i = 19; i >= 0; i--){
        if (spt[i][u] != spt[i][v]){
            u = spt[i][u];
            v = spt[i][v];
        }
    }
    if (u != v) u = spt[0][u];
    return u;
}

bool conn[2020202];

void dfs(int v, int pv = -1){
    if (v == 1) conn[v] = 1;

    // merge
    for(auto f : nadj[v]) if (f != pv) {
        dfs(f, v);
        conn[v] |= conn[f];
        if (int(minV[v].size()) < int(minV[f].size())) {
            swap(minV[v], minV[f]);
        }
        for(auto s : minV[f]) minV[v].insert(s);
    }
    // merge done

    // add
    for(auto f : cadj[v]) if (f != pv) {
        int L = lca(v, f);
        int val = dep[v] + 1 + dep[f];
        minV[v].insert(mp(val, dep[L]));
    }

   // cout << "Go " << v << ' ' << dep[v] << " : ";
    //for(auto[a,b] : minV[v]) cout << a << ' '<< b << " | ";
   // cout << '\n';

    while(!minV[v].empty() && (*minV[v].begin()).y >= dep[v]){
        minV[v].erase(minV[v].begin());
    }

    
    if (v != n && conn[v] && minV[v].empty()){
        // cut edge
        cout << -1 << '\n';
        exit(0);
    }
   if (!minV[v].empty()) d2[v] = (*minV[v].begin()).x - dep[v];
   else d2[v] = 2020202;

}

void solve(){
    
    cin >> n >> m;
    vector<pair<int, int>> edg;
    while(m--){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int, int>> nedg;
    queue<int> q;
    q.push(n);
    vector<int> from(n+1, -1);
    from[n] = n;
    while(!q.empty()){
        int a = q.front(); q.pop();
        for(auto f : adj[a]){
            if (from[f] != -1) {
                // cross edge
                if (from[a] != f){
                    // cout << "cross: " << a << ' ' << f << '\n';
                    cadj[a].push_back(f);
                    //cadj[f].push_back(a);
                }
                continue;
            }
            q.push(f);
            from[f] = a;
            dep[f] = dep[a] + 1;
            spt[0][f] = a;
           // cout << "tree Edg: " << a << ' ' << f << '\n';
            nedg.push_back(mp(f, a));
        }
    }

    for(int i = 1; i < 20 ;i++){
        for(int j = 1; j <= n; j++){
            spt[i][j] = spt[i-1][spt[i-1][j]];
        }
    }

    for(auto[a,b] : nedg){
        nadj[a].push_back(b);
        nadj[b].push_back(a);
    }

    memset(d2, -1, sizeof d2);
    dfs(n);
    d2[n] = 0;
    
    vector<int> dp(n+1);
    for(int i = 1; i <= n; i++) dp[i] = d2[i];

    vector<bool> chk(n+1);
    chk[n] = 1;
    set<pair<int, int>> st;
    st.insert(mp(0, n));

    while(!st.empty()){
        auto[a,b] = *st.begin();
        st.erase(st.begin());

        if (dp[b] != a) continue;
       // cout << "Go: " << b << ' ' << a << '\n';
        for(auto f : adj[b]){
            if(!chk[f]){
                dp[f] = max(d2[f], dp[b] + 1);
                //cout << "Upd: " << f << " | " << d2[f] << ' ' << dp[b] + 1 << '\n';
                chk[f] = 1;
                st.insert(mp(dp[f], f));
            }
        }
    }

    cout << dp[1] << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}