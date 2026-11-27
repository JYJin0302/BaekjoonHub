#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int root[200001];
int sz[200001];
int find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i =1 ; i <= n; i++) {
        root[i] = i;
        sz[i] = 1;
    }
    
    const ll mod = 1e9+7;
    
    while(m--){
        
        int a, b;
        cin >> a >> b;
        
        a= find(a), b =find(b);
        
        if (a != b){
            root[b] = a;
            sz[a] += sz[b];
        }
    }
    
    ll ans = 1;
    for (int i = 1; i <= n; i++){
        if (i == find(i)) ans = ans*sz[i] % mod;
    }
    cout << ans;
}