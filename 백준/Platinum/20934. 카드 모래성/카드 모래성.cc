#include <bits/stdc++.h>
using namespace std;

int n;
int A[201];

int g[201][201];
int ans[201][201];
int solve(int l, int r){
    if (l >= r) return 0;
    if (g[l][r] != -1) return g[l][r];
    
    
    ans[l][r] = -1;
    vector<int> cnt(300);
    for(int i = l; i < r; i++){
        if (i + A[i] <= r) {
            int tx = solve(l, i-1)^solve(i+A[i]+1, r);
            cnt[tx]++;
            if (tx == 0 && ans[l][r] == -1) ans[l][r] = i;
        }
    }
    
    int x = 0;
    while(cnt[x]) x++;
    return g[l][r] = x;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i];
    
    memset(g, -1, sizeof(g));
    memset(ans, -1, sizeof(ans));
    
    solve(1, n);
    cout << ans[1][n];
}