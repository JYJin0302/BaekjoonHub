#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<pair<int, int>> adj[10001];
int dist[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        int n, m, c;
        cin >> n >> m >> c;
        
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            dist[i] = -1;
        }
        
        while(m--){
            int a, b, c;
            cin >> a >> b >> c;
            
            adj[b].push_back({a, c});
        }
        
        int cnt = 0, ans = 0;
        
        priority_queue<pair<int, int>> pq;
        pq.push({0, c});
        while(!pq.empty()){
            
            int a, b;
            tie(a, b) = pq.top();
            pq.pop();
            
            if (dist[b] != -1) continue;
            dist[b] = -a;
            
            cnt++;
            ans = max(ans, -a);
            for (auto i : adj[b]) {
                if (dist[i.x] == -1){
                    pq.push({a - i.y, i.x});
                }
            }
        }
        
        cout << cnt << ' ' << ans << '\n';
    }
}