#include <bits/stdc++.h>
using namespace std;

int h, w;
string grid[21];

int g[21][21][21][21]; // 좌측상단 -> 우측하단

bool inGrid(int x, int y){
    return x >= 0 && x < h && y >= 0 && y < w;
}

int solve(int x1, int y1, int x2, int y2){
    
    if (g[x1][y1][x2][y2] != -1) return g[x1][y1][x2][y2];
    if (x1 > x2 || y1 > y2) return g[x1][y1][x2][y2] = 0;
    if (!inGrid(x1, y1) || !inGrid(x2, y2)) return g[x1][y1][x2][y2] = 0;
    
    vector<int> cnt(100);
    
    for (int i = x1; i <= x2; i++){
        for (int j = y1; j <= y2; j++){
            
            if (grid[i][j] == 'X') continue;
            int v = solve(x1, y1, i-1, j-1);
            v ^= solve(x1, j+1, i-1, y2);
            v ^= solve(i+1, y1, x2, j-1);
            v ^= solve(i+1, j+1, x2, y2);
            if (v < 100) cnt[v]++;
        }
    }
    int r = 0;
    while(cnt[r] != 0) r++;
    return g[x1][y1][x2][y2] = r;
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(g, -1, sizeof(g));
    
    cin >> h >> w;
    for(int i = 0; i < h; i++) cin >> grid[i];
    
    if(solve(0, 0, h-1, w-1) > 0) cout << "First";
    else cout << "Second";
}