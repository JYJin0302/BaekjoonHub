#include <bits/stdc++.h>
using namespace std;

vector<int> adj[51];
int topo[51];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<string> A(n);
    for(auto& i : A) cin >> i;
    
    for (int i = 0; i < n; i++){
        for (int j=  0; j < n; j++){
            if (A[i][j] == '1'){
                adj[j].push_back(i);
                topo[i]++;
            }
        }
    }
    
    int v = n;
    vector<int> ans(n);
    
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) if (topo[i] == 0) pq.push(i);
    
    while(!pq.empty()){
        
        int a=pq.top();
        pq.pop();
        
        ans[a] = v;
        v--;
        
        for (auto i : adj[a]){
            topo[i]--;
            if (topo[i] ==0) pq.push(i);
        }
    }
    
    if (v != 0) cout << -1;
    else for(auto i : ans) cout << i << ' ';
}