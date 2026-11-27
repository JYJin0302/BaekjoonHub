#include <bits/stdc++.h>
using namespace std;

int root[1001];
int find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

vector<int> E[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) root[i] = i;
    int ans = n;
    
    for(int i = 0; i < m; i++){
        char c;
        int a, b;
        cin >> c >> a >> b;
        
        if (c == 'E'){
            E[a].push_back(b);
            E[b].push_back(a);
        }
        else{
            a = find(a), b = find(b);
            if (a != b){
                ans--;
                root[b] = a;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if (E[i].empty()) continue;
        
        int k = E[i][0];
        for(int j = 1; j < E[i].size(); j++){
            int tk = E[i][j];
            k = find(k), tk = find(tk);
            if (tk != k){
                ans--;
                root[tk] = k;
            }
        }
    }
    
    cout << ans;
}