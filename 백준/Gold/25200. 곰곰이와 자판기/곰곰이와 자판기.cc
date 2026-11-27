#include <bits/stdc++.h>
using namespace std;

vector<int> root;
int find(int n){
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    root = vector<int>(n+1);
    for(int i = 1; i <= n; i++) root[i] = i;
    vector<int> col = root;
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        
        int ca = col[a], cb= col[b];
        int fa = find(ca), fb = find(cb);
        
        if (fa != 0){
            if (fb == 0){
                col[b] = fa;
                col[a] = 0;
            }
            else{
                root[fa] = fb;
                col[a] = 0;
            }
        }
    }
    
    vector<int> ans(n+1);
    for (int i =1 ; i <= n; i++){
        ans[col[i]] = i;
    }
    
    for (int i = 1; i <= n; i++){
        cout << ans[find(i)] << ' ';
    }
    
}