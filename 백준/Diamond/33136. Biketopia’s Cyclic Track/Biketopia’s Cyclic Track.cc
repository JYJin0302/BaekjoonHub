#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<int, int>> adj[202020];
pair<int, int> from[202020];
int dep[202020];
bool used[303030];

vector<int> eLst;

void dfs(int v, int pv = -1){
    for(auto[a,b] : adj[v]) if (a != pv){
        if (dep[a] == -1){
            dep[a] = dep[v] + 1;
            used[b] = 1;
            dfs(a, v);
        }
    }
}


void solve() { 
    
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edg;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a>> b;
        edg.push_back(mp(a, b));
        adj[a].push_back(mp( b, i));
        adj[b].push_back(mp(a, i));
    }

    memset(dep, -1, sizeof dep);
    dep[1] = 0;
    dfs(1);

    int v = -1;
    int ans = -1;
    for(int i = 0;i < m; i++){
        if (used[i]) continue;
        int D = min(dep[edg[i].x], dep[edg[i].y]);
        if (v < D){
            v = D;
            ans = i;
        }
    }
   // cout << "Go: " << edg[ans].x << ' ' << edg[ans].y << '\n';
    int s = edg[ans].x;
    queue<int> q;
    q.push(s);
    from[s] = mp(s, s);
    while(!q.empty()){
        int a= q.front(); q.pop();
        for(auto[u, v] : adj[a]) if (used[v]) {
            if (from[u].x == 0){
                from[u] = mp(a, v);
                q.push(u);
            }
        }
    }
    
    
    vector<int> track;
    track.push_back(ans);
    int cur= edg[ans].y;
    while(cur != edg[ans].x){
        track.push_back(from[cur].y);
        cur = from[cur].x;
    }

    cout << track.size() << '\n';
    for(auto f : track) cout <<f + 1<< ' ';
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