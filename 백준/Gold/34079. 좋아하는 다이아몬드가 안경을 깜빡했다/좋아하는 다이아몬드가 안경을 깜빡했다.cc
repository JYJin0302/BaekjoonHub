#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

vector<int> adj[202020];
int dist[202020];

void solve(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()){
        int a= q.front() ;q.pop();
        for(auto f : adj[a])if(dist[f] == -1){
            dist[f] = dist[a] + 1;
            q.push(f);
        }
    }

    int ans = -1;
    q.push(1);
    queue<int> tq;
    vector<bool> inQ(n+1);
    int D = dist[1];
    while(1){
        --D;
        if (D == 0) break;

        while(!q.empty()){
            int a= q.front(); q.pop();
            for(auto f: adj[a])if (dist[f] == D && !inQ[f]){
                inQ[f] = 1;
                tq.push(f);
            }
        }

        if (tq.size() == 1){
            ans = tq.front();
            break;
        }
        swap(q, tq);
    }

    if (ans == -1) ans = 1;
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}