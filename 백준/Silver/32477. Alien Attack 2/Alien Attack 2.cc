#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[202020];

bool vis[202020];
int cnt = 0;
void dfs(int v){
    vis[v] = 1;
    cnt++;
    for(auto f : adj[v]){
        if (!vis[f]){
            dfs(f);
        }
    }
}

void solve(){
    
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int ans = 0;
    for(int i =1;i <= n; i++){
        if (!vis[i]){
            cnt = 0;
            dfs(i);
            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
