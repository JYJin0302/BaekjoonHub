#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, c;
    cin >> n >> m >> c;
    
    vector<int> A(n+1);
    for(int i = 1; i <= n; i++) cin >> A[i];
    
    vector<vector<pair<int, int>>> adj(n+1);
    vector<int> topo(n+1);
    for (int i = 0; i < c; i++){
        int a, b, d;
        cin >> a >> b >> d;
        
        adj[a].push_back({b, d});
        topo[b]++;
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if (topo[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        
        int a = q.front();
        q.pop();
        
        for (auto i : adj[a]){
            A[i.x] = max(A[i.x], A[a] + i.y);
            topo[i.x]--;
            
            if (topo[i.x] == 0) q.push(i.x);
        }
    }
    
    for (int i = 1; i <= n; i++) cout << A[i] << ' ';
}