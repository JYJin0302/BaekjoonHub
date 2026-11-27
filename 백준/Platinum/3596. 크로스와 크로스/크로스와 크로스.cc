#include <bits/stdc++.h>
using namespace std;

int g[2001];
int solve(int x){
    if (x < 0) return 0;
    if (g[x] != -1) return g[x];
    if (x == 0) return g[x] = 0;
    
    vector<int> cnt(201);
    
    for(int i = 1; i <= x; i++){
        cnt[solve(i-3)^solve(x-i-2)]++;
    }
    int r = 0;
    while(cnt[r])r++;
    return g[x] = r;
}
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(g, -1, sizeof(g));
    
    int n;
    cin >> n;
    
    if (solve(n)) cout << 1;
    else cout << 2;
}
