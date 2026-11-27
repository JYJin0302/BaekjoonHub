#include <bits/stdc++.h>
using namespace std;

vector<int> adj[3030];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> deg(n+1);
    while(m--){
        int a, b;
        cin >> a>> b;
        deg[a]++;
        deg[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> vs(n+1);
    vs[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int a=  q.front();
        q.pop();
        
        for(auto i : adj[a])if(!vs[i]){
            vs[i] = 1;
            q.push(i);
        }
    }
    
    int oc = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i] &1) oc++;
        if(!vs[i]) oc += 100;
    }
    
    if (oc == 0 || oc == 2) cout << "YES";
    else cout << "NO";
    
}