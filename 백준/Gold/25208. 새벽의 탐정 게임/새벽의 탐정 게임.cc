#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] ={-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

// up, down, left, right, front, back


vector<int> mov[4];

int dp[6][501][501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // init
    memset(dp, -1, sizeof(dp));
    mov[0] = {5, 4, 2, 3, 0, 1};
    mov[1] = {0, 1, 5, 4, 2, 3};
    mov[2] = {4, 5, 2, 3, 1, 0};
    mov[3] = {0, 1, 4, 5, 3, 2};
    
    cin >> n >> m;
    
    vector<string> A(n);
    for(auto& i : A) cin>> i;
    
    int ix, iy, ex, ey;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (A[i][j] == 'D') ix = i, iy = j;
            else if (A[i][j] == 'R') ex = i, ey = j;
        }
    }
    
    queue<tuple<int, int, int>> q;
    q.push({5, ix, iy});
    dp[5][ix][iy] = 0;
    while(!q.empty()){
        
        int t, x, y;
        tie(t, x, y) = q.front();
        q.pop();
        
        if (x == ex && y == ey) continue;
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int nt = mov[i][t];
            if (inGrid(nx, ny) && A[nx][ny] != '#' && dp[nt][nx][ny] == -1){
                dp[nt][nx][ny] = dp[t][x][y] + 1;
                q.push({nt, nx, ny});
            }
        }
        
    }
    
    cout << dp[5][ex][ey];
    
}