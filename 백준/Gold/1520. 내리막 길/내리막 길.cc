#include <bits/stdc++.h>
using namespace std;


int n, m;
int grid[501][501];
int path[501][501];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y< m;
}

void dfs(int x = 0, int y = 0){
    if (path[x][y] != -1) return;
    
    path[x][y] = 0;
    for (int i = 0; i < 4; i++){
        int nx =x +dx[i];
        int ny =y + dy[i];
        if (inGrid(nx, ny) && grid[nx][ny] < grid[x][y]){
            dfs(nx, ny);
            path[x][y] += path[nx][ny];
        }
    }
    
}


int main(){
   
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    memset(path, -1, sizeof(path));
    path[n-1][m-1] = 1;
    dfs();
    
    cout << path[0][0];
}