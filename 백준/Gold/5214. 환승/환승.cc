#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101001];
int dist[101001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, m;
    cin >> n >> k >> m;
    
    for(int i = 1; i <= m; i++){
        int x;
        for(int j = 0; j < k; j++){
            cin >> x;
            adj[x].push_back(i + 100000);
            adj[i+100000].push_back(x);
        }
    }
    
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        
        int a = q.front();
        q.pop();
        
        for (auto i : adj[a]) {
            if (dist[i] == -1){
                dist[i] = dist[a] + 1;
                q.push(i);
            }
        }
    }
    
    if (dist[n] == -1) cout << -1;
    else cout << dist[n] / 2 + 1;
}