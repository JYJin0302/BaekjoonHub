#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<pair<int, int>> adj[100001];

vector<int> len;
int dist[100001];

int s = -1, e = -1, mval = 0, val = 1e9, mlen = 0;

void dfs(int v, int pv = -1){
    for (auto i : adj[v]) if (i.x != pv){
        dist[i.x] = dist[v] + i.y;
        dfs(i.x, v);
        if (dist[i.x] > mval) {
            mval = dist[i.x];
            if (e == -1) s = i.x;
            else e = i.x;
        }
    }
    
}

void dfs_clear(int v, int pv = -1){
    dist[v] = 0;
    for (auto i : adj[v]) if (i.x != pv){
        dfs_clear(i.x, v);
    }
}

void backtrack(int v, int pv = -1){
    val = min(val, max(dist[v], dist[e] - dist[v]));
    for (auto i : adj[v]) {
        if (dist[i.x] + i.y == dist[v]){
            backtrack(i.x);
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dist, -1 ,sizeof(dist));
    int n, m, l;
    cin >> n >> m >> l;
    
    if (m == 0) {
        if (n == 1) cout << 0;
        else if (n == 2) cout << l;
        else cout << l*2;
        return 0;
    }
    
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for(int i = 0; i < n; i++){
        if (dist[i] == -1){
            s = i;
            e = -1;
            mval = 0;
            dist[i] = 0;
            
            dfs(i);
            
            dfs_clear(i);
            mval = 0;
            e = i;
            
            dfs(s);
            
            mlen = max(mlen, dist[e]);
            
            val = 1e9;
            backtrack(e);
            len.push_back(val);
        }
    }
    
    sort(len.rbegin(), len.rend());
    
    if (len.size() == 1) cout << max(mlen, len[0]);
    else if (len.size() == 2) cout << max(mlen, len[0] + len[1] + l);
    else cout << max({mlen, len[0]+len[1]+l, len[1]+len[2]+2*l});
    
}