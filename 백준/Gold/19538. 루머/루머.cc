#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        
        while(x){
            adj[i].push_back(x);
            cin >> x;
        }
    }
    
    int m;
    cin >> m;
    
    vector<int> cnt(n+1);
    vector<int> ans(n+1, -1);
    queue<int> q;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        
        ans[x] = 0;
        q.push(x);
    }
    
    while(!q.empty()){
        
        int a = q.front();
        q.pop();
        
        for (auto i : adj[a]) if (ans[i] == -1) {
            cnt[i]++;
            
            if (cnt[i] >= (adj[i].size() + 1) / 2){
                ans[i] = ans[a] + 1;
                q.push(i);
            }
        }
    }
    
    for(int i =1 ; i <=n ; i++) cout  << ans[i] << ' ';
    
}