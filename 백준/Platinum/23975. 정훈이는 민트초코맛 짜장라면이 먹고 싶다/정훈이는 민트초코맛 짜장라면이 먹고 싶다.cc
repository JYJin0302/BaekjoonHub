#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int root[1000001];
int dist[1000001];
int conv[1000001];
vector<pair<int, int>> adj[1000001];

int find(int n){
    if(root[n] == n) return n;
    return root[n] = find(root[n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    memset(dist, -1, sizeof(dist));
    
    for(int i = 1; i <= n; i++) cin >> conv[i];
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        
        int a, b;
        tie(a, b) = pq.top();
        pq.pop();
        
        if (dist[b] != -1) continue;
        dist[b] = -a;
        
        for (auto i : adj[b]) if (dist[i.x] == -1){
            pq.push({a - i.y, i.x});
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (dist[i] == -1) continue;
        int nxt = 0;
        for (auto k : adj[i]) if (dist[k.x] != -1 && dist[k.x] + k.y == dist[i]) nxt = max(nxt, k.x);
        if (nxt == 0) nxt = i;
        root[i] = nxt;
    }
    
    while(k--){
        
        int a;
        cin >> a;
        
        if (dist[a] == -1) cout << -1 << '\n';
        else{
            
            int ta = a;
            while(ta != 1 && conv[ta] == 0){
                ta = root[ta];
            }
            
            if (conv[ta] == 0) cout << -1 << '\n';
            else {
                conv[ta]--;
                cout << ta << '\n';
            }
            if (a != ta) root[a] = ta;
        }
    }
}