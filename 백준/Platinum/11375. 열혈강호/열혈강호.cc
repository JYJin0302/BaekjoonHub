#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int match[1001], c[1001];

bool dfs(int l){
    if (c[l]) return 0;
    c[l] = 1;
    
    for (auto i : adj[l]){
        if (match[i] == 0 || dfs(match[i])){
            match[i] = l;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        
        while(x--){
            int b;
            cin >> b;
            adj[i].push_back(b);
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        memset(c, 0, sizeof(c));
        cnt += dfs(i);
    }
    
    cout << cnt;
}