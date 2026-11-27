#include <bits/stdc++.h>
using namespace std;

int n;
bool rid = 1, val = 1;
int grid[1001][1001], v[1001][1001];

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y){
    v[x][y] = 1;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!inGrid(nx, ny)) continue;
        
        if (grid[nx][ny] == grid[x][y]){
            if (!v[nx][ny]) dfs(nx, ny);
        } 
        else if (grid[nx][ny] > grid[x][y]) rid = 0;
        else val = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (v[i][j] == 0) {
                rid = 1, val = 1;
                dfs(i, j);
                ans1 += rid;
                ans2 += val;
            }
        }
    }
    
    cout <<  ans1 << ' ' << ans2;
}