#include <bits/stdc++.h>
using namespace std;

vector<int> root;
int find(int n){
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}

bool used[50][50];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    root = vector<int>(n);
    for (int i = 0; i < n; i++) root[i] = i;
    
    vector<string> edge(n);
    for(auto& i : edge) cin >> i;
    
    vector<pair<int, int>> ans;    
    
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            
            find(i), find(j);
            if (edge[i][j] == 'Y' && root[i] != root[j]){
                used[i][j] = 1;
                root[root[i]] = root[j];
                ans.push_back({i, j});
                cnt++;
            }
        }
    }
    
    bool ok = 1;
    if (cnt != n-1) ok = 0;
    
    for (int i = 0; i < n; i++){
        if (cnt == m) break;
        for (int j = i + 1; j < n; j++){
            if (cnt == m) break;
            
            if (!used[i][j] && edge[i][j] == 'Y'){
                used[i][j] = 1;
                cnt++;
                ans.push_back({i, j});
            }
        }        
    }
    
    if (cnt != m) ok = 0;
    
    if (!ok){
        cout << -1;
        return 0;
    }
    
    vector<int> res(n);
    for(auto i : ans){
        res[i.first]++;
        res[i.second]++;
    }
    
    for(int i : res) cout << i << ' ';
    
}