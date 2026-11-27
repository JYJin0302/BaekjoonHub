#include <bits/stdc++.h>
using namespace std;

int p, k, n;
int A[1001];
int g[1001];

int solve(int idx){
    
    if (idx == -1) return 0;
    if (idx < -1) return 15;
    if (g[idx] != -1) return g[idx];
    
    vector<int> cnt(20);
    
    for (int i = 0; i <= k; i++){
        int ni = idx - i;
        if (ni >= 0) cnt[solve(ni - A[ni])]++;
    }
    
    int r = 0;
    while(cnt[r])r++;
    return g[idx] = r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> p >> k;
    
    int r = 0;
    while(p--){
        
        cin >> n;
        for(int i = 0; i < n; i++) cin >> A[i];
        
        memset(g, -1, sizeof(g));
        r ^= solve(n-1);
    }
    
    if (r > 0) cout << "Alice can win.";
    else cout << "Bob will win.";
}