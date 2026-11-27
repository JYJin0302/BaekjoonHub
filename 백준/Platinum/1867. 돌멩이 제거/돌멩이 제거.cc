#include <bits/stdc++.h>
using namespace std;

int co[501], match[501];
vector<int> adj[501];

bool dfs(int i){
    if (co[i]) return 0;
    co[i] = 1;
    
    for (auto j : adj[i]) {
        if (match[j] == -1 || dfs(match[j])){
            match[j] = i;
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
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    memset(match, -1, sizeof(match));
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        memset(co, 0, sizeof(co));
        cnt += dfs(i);
    }
    cout << cnt;
}