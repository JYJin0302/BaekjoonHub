#include <bits/stdc++.h>
using namespace std;

int n, val, ans = 0;
vector<int> A,B;
void dfs(int v){
    if (v*2 < n){
        dfs(v*2), dfs(v*2+1);
        B[v] = max(B[v*2] + A[v*2], B[v*2+1] + A[v*2+1]);
    }
}

void dfs2(int v, int t){
    
    if (v*2 < n){
        ans += t-B[v*2];
        dfs2(v*2, B[v*2]);
        ans += t-B[v*2+1];
        dfs2(v*2+1, B[v*2+1]);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k;
    cin >> k;
    
    n = pow(2, k+1);
    
    A = vector<int> (n+1);
    B = vector<int> (n+1);
    for (int i = 2; i <= n; i++) cin >> A[i];
    dfs(1);
    
    //for(int i = 1; i <= n; i++) cout << B[i] << ' ';
    
    val = B[1];
    dfs2(1, val);
    
    cout << ans;
}