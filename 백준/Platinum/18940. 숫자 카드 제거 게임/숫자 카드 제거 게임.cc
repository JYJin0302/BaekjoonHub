#include <bits/stdc++.h>
using namespace std;

int g[111];
int solve(int x){
    if (g[x] != -1) return g[x];
    if (x == 0) return g[x] = 0;
    
    vector<int> cnt(15);
    for(int i = 1; i <= x; i++){
        cnt[solve(max(0, i-2)) ^ solve(max(0, x - i - 1))]++;
    }
    int r = 0;
    while(cnt[r] > 0) r++;
    return g[x] = r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(g, -1, sizeof(g));
    for(int i = 0; i <= 110; i++) solve(i);
    
    int t;
    cin >> t;
    while(t--){
        
        int n, v;
        cin >> n;
        
        if (n <= 100) v = solve(n);
        else v = solve(n % 34 + 68);
        
        if (v != 0) cout << "Yuto\n";
        else cout << "Platina\n";
    }
}