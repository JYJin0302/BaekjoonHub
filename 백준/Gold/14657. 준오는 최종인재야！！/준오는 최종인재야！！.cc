#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<pair<int, int>> adj[50001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    vector<pair<int, int>> dist(n+1, {-1, 0}); // 개수, 거리
    dist[1] = {1, 0};
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        
        int a = q.front();
        q.pop();
        
        for (auto i : adj[a]) if (dist[i.x].x == -1){
            dist[i.x].x = dist[a].x + 1;
            dist[i.x].y = dist[a].y + i.y;
            q.push(i.x);
        }
    }
    
    int f = 1;
    int val = 0;
    for(int i = 1; i <= n; i++){
        if (dist[i].x > val || (dist[i].x == val && dist[i].y < dist[f].y)) {
            val = dist[i].x;
            f = i;
        }
    }
    
    dist = vector<pair<int, int>> (n+1, {-1, -1});
    dist[f] = {1, 0};
    q.push(f);
    while(!q.empty()){
        
        int a = q.front();
        q.pop();
        
        for (auto i : adj[a]) if (dist[i.x].x == -1){
            dist[i.x].x = dist[a].x + 1;
            dist[i.x].y = dist[a].y + i.y;
            q.push(i.x);
        }
    }
    
    f = 0;
    val = 0;
    for(int i = 1; i <= n; i++){
        if (dist[i].x > val || (dist[i].x == val && dist[i].y < dist[f].y)) {
            val = dist[i].x;
            f = i;
        }
    }
    
    cout << (dist[f].y + t - 1) / t;
}