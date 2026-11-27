#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, h, r, ans;
vector<pair<int, int>> adj[10001];
int dist[10001];
int distM[10001];

void dfs(int v){
    for (auto i : adj[v]){
        dist[i.x] = dist[v] + i.y;
        dfs(i.x);
        distM[v] = max(distM[v], distM[i.x]+i.y);
    }
}

void dfs(int v, int th){
    
    if (distM[v] <= th) return;
    
    for (auto i : adj[v]) {
        if (distM[i.x] + i.y > th){
            int tv = min(i.y, i.y + distM[i.x] - th);
            dfs(i.x, th - (i.y - tv));
            ans += tv;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> h;
    
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        
        if (a == 0 && b== 0) r = i;
        else{
            adj[a].push_back({i, b});
        }
    }
    
    dfs(r);
    dfs(r, h);
    cout << ans;
}