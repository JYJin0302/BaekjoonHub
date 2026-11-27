#include <bits/stdc++.h>
using namespace std;

int ans = 101;
int grid[10][10], tgrid[10][10];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void press(int x, int y){
    
    tgrid[x][y] = 1 - tgrid[x][y];
    
    for (int i = 0; i <4 ;i ++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
            tgrid[nx][ny] = 1 - tgrid[nx][ny];
        }
    }
    
}

int main(){
    
    for (int i = 0; i < 10; i++){
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++){
            grid[i][j] = (s[j] == 'O');
        }
    }
    
    for (int i = 0; i < (1 << 10); i++){
        
        int cnt = 0;
        
        // init
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < 10; k++){
                tgrid[j][k] = grid[j][k];
            }
        }
        
        for (int j = 0; j < 10; j++){
            if (i & (1 << j)) press(0, j), cnt++;
        }
        
        // test
        
        for(int j = 1; j < 10; j++){
            for (int k = 0; k < 10; k++){
                if (tgrid[j-1][k]) press(j, k), cnt++;
            }
        }
        
        bool ok = 1;
        for (int j =0; j < 10; j++) if (tgrid[9][j]) ok = 0;
        
        if (ok) ans = min(ans, cnt);
        
    }
    
    if (ans == 101) ans = -1;
    cout << ans;
    
}