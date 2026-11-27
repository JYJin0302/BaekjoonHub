#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int C[202020];
vector<int> adj[202020];
int dp[202020];

int D[202020];

void dfs(int v, int pv = -1){
    dp[v] = C[v];
    for(auto f : adj[v]) if (f != pv){
        dfs(f, v);
        dp[v] += dp[f];
    }
}

void dfs2(int v, int pv = -1, int dpU = 0){

    int tot = 0;
    for(auto f : adj[v]) if (f != pv){
        tot += dp[f];
    }

    if (tot * C[v] >= 0){
        if (pv != -1) D[1]++, D[v]--;
       // cout << "GO: " << v << " -> " << pv << endl;
    }

    tot += dpU;
    for(auto f : adj[v]) if (f != pv){
        tot -= dp[f];
        if (tot * C[v] >= 0) {
            D[f]++;
            //cout << "Go :" << v << " -> " << f << endl;
        }
        dfs2(f, v, tot + C[v]);
        tot += dp[f];
    }
}

void setDp(int v, int pv = -1){
    for(auto f: adj[v]) if (f != pv){
        D[f] += D[v];
        setDp(f, v);
    }
}

void solve(){

    int n;
    cin >> n;

    for(int i = 1 ;i <= n; i++){
        cin >> C[i];
        if (C[i] == 0) C[i] = -1;
    }
    for(int i =0 ; i < n-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);

    dfs2(1);

    setDp(1);

    vector<int> ans;
    int val = dp[1];
    for(int i =1 ; i <= n; i++) {
        val -= C[i];
        if (val * C[i] >= 0) D[i]++;
        if (D[i] == n) ans.push_back(i);
        val += C[i];
    }
    
    cout << (int)ans.size() << '\n';
    for(auto f : ans) cout <<f << ' ';
    cout << '\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}