#include <bits/stdc++.h>
using namespace std;

vector<int> root;
int find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    
    root = vector<int>(n+1);
    for(int i= 1; i <= n ; i++) root[i] = i;
    
    vector<tuple<int, int, int>> A(m);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        A[i] = {c, a, b};
    }
    
    sort(A.begin(), A.end());
    
    int ans = (n - 2) * (n-1) / 2 * t;
    for(auto i : A){
        int a, b, c;
        tie(a, b, c) = i;
        
        b = find(b), c = find(c);
        if(root[b] != root[c]){
            ans += a;
            root[c] = b;
        }
    }
    cout << ans;
}