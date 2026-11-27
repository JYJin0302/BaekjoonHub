#include <bits/stdc++.h>
using namespace std;

vector<int> root;
int find(int n){
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}

int main(){
    
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    root = vector<int>(n);
    for (int i = 0; i < n; i++) root[i] = i;
    
    int ans = 0;
    for (int i = 0; i < m; i++){
        
        int a, b;
        cin >> a >> b;
        
        a = find(a), b = find(b);
        if (root[a] == root[b] && ans == 0) ans = i + 1;
        
        root[a] = b;
    }
    
    cout << ans;
    
}