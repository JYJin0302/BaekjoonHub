#include <bits/stdc++.h>
using namespace std;

int path[1001][1001];
vector<int> adj[1001];

int adj_idx[1001];
vector<int> ans;

void dfs(int v){
    
    int &k = adj_idx[v];
    while(k < adj[v].size()){
        int nk = adj[v][k];
        if (path[v][nk] != 0){
            path[v][nk]--;
            path[nk][v]--;
            dfs(nk);
        }
        k++;
    }
    cout << v+1 << ' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++){
            cin >> path[i][j];
            if (path[i][j] > 0) adj[i].push_back(j);
            cnt += path[i][j];
        }
        if (cnt % 2 == 1){
            cout << -1;
            return 0;
        }
    }
    
    
    int cnt_odd = 0;
    for (int i = 0; i < n; i++){
        cnt_odd += (adj[i].size() % 2);
    }
    
    dfs(0);
}