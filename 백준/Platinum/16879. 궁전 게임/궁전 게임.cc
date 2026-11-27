#include <bits/stdc++.h>
using namespace std;

int g[12][12];

int solve(int x, int y){
    if (x > y) swap(x, y);
    
    if (g[x][y] != -1) return g[x][y];
    if (x == 0 && y == 0) return g[x][y] = 0;
    
    vector<int> cnt(13);
    for(int i = 0; i < x; i++) cnt[solve(i, y)]++;
    for(int j = 0; j < y; j++) cnt[solve(x, j)]++;
    if (x > 0 && y > 0) cnt[solve(x-1, y-1)]++;
    
    int r = 0;
    while(cnt[r] > 0) r++;
    return g[x][y] = r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    memset(g, -1, sizeof(g));
    int ans = 0;
    while(n--){
        
        int x, y;
        cin >> x >> y;
        
        int tx = x / 12, ty = y / 12;
        ans ^= solve(x%12, y%12) + (tx^ty)*12;
    }
    
    if(ans != 0) cout << "koosaga";
    else cout << "cubelover";
}