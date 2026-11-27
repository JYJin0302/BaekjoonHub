#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
int grid[6][21][21];
int tmp_grid[21][21];

int tilt_set[5];

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void copyGrid(int idx){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            tmp_grid[i][j] = grid[idx][i][j];
        }
    }
}
void updateGrid(int idx){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            grid[idx][i][j] = tmp_grid[i][j];
        }
    }
}

int gridVal(){
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            res = max(res, tmp_grid[i][j]);
        }
    }
    return res;
}

void tilt(int dir){
    // dir: 0-왼쪽, 1-위, 2-아래, 3-오른쪽
    
    bool u[21][21];
    for (int i = 0; i < n; i++) for(int j = 0; j < n; j++) u[i][j] = 0;
    
    if (dir==0){
        
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (tmp_grid[i][j] == 0) continue;
                int v = tmp_grid[i][j];
                tmp_grid[i][j] = 0;
                
                int tj = j;
                while(inGrid(i, tj) && tmp_grid[i][tj] == 0) tj--;
                
                if (inGrid(i, tj) && v == tmp_grid[i][tj] && !u[i][tj]){
                    // union
                    u[i][tj] = 1;
                    tmp_grid[i][tj] += v;
                }
                else tmp_grid[i][tj+1] = v;
            }
        }
        return;
    }
    
    if (dir == 1){
        
        for (int j = 0; j < n; j++){
            for (int i = 0; i < n; i++){
                if (tmp_grid[i][j] == 0) continue;
                int v = tmp_grid[i][j];
                tmp_grid[i][j] = 0;
                
                int ti = i;
                while(inGrid(ti, j) && tmp_grid[ti][j] == 0) ti--;
                
                if (inGrid(ti, j) && v == tmp_grid[ti][j] && !u[ti][j]){
                    // union
                    u[ti][j] = 1;
                    tmp_grid[ti][j] += v;
                }
                else tmp_grid[ti+1][j] = v;
                
            }
        }
        return;
    }
    
    if (dir==2){
        
        for(int i = 0; i < n; i++){
            for (int j = n-1; j >= 0; j--){
                if (tmp_grid[i][j] == 0) continue;
                int v = tmp_grid[i][j];
                tmp_grid[i][j] = 0;
                
                int tj = j;
                while(inGrid(i, tj) && tmp_grid[i][tj] == 0) tj++;
                
                if (inGrid(i, tj) && v == tmp_grid[i][tj] && !u[i][tj]){
                    // union
                    u[i][tj] = 1;
                    tmp_grid[i][tj] += v;
                }
                else tmp_grid[i][tj-1] = v;
            }
        }
        return;
    }
    
    if (dir == 3){
        
        for (int j = 0; j < n; j++){
            for (int i = n-1; i >= 0; i--){
                if (tmp_grid[i][j] == 0) continue;
                int v = tmp_grid[i][j];
                tmp_grid[i][j] = 0;
                
                int ti = i;
                while(inGrid(ti, j) && tmp_grid[ti][j] == 0) ti++;
                
                if (inGrid(ti, j) && v == tmp_grid[ti][j] && !u[ti][j]){
                    // union
                    u[ti][j] = 1;
                    tmp_grid[ti][j] += v;
                }
                else tmp_grid[ti-1][j] = v;
            }
        }
        return;
    }
}

void solve(int cnt = 0){
    
    if (cnt == 5) {
        ans = max(ans, gridVal());
        return;
    }
    
    for (int i = 0; i < 4; i++){
        copyGrid(cnt);        
        tilt(i);
        updateGrid(cnt+1);
        solve(cnt+1);
    }
}


int main(){
    
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[0][i][j];
        }
    }
    
    copyGrid(0);
    solve();
    cout << ans;
}