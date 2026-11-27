#include <bits/stdc++.h>
using namespace std;

int l, r, c;

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

bool inGrid(int z, int x, int y){
    return z >= 0 && z < l && x >= 0 && x < r && y >= 0 && y < c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> l >> r >> c;
    
    while(l!=0 && r!=0 && c!=0){
        
        int sz, sx, sy;
        int ez, ex, ey;
        string A[30][30];
        for (int i = 0; i < l; i++){
            for (int j = 0; j < r; j++){
                string s;
                cin >> s;
                A[i][j] = s;
                for (int k = 0; k< c; k++) {
                    if (A[i][j][k] == 'S'){
                        sz = i, sx = j, sy = k;
                    }
                    if (A[i][j][k] == 'E'){
                        ez = i, ex = j, ey = k;
                    }
                }
            }
        }
        
        bool v[30][30][30];
        int d[30][30][30];
        
        for (int i = 0; i < l; i++) for(int j = 0; j < r; j++) for (int k = 0; k < c; k++) {
            v[i][j][k] = 0;
            d[i][j][k] = 0;
        }
        
        queue<tuple<int, int, int>> q;
        q.push({sz, sx, sy});
        v[sz][sx][sy] = 1;
        while(!q.empty()){
            int z, x, y;
            tie(z, x, y) = q.front();
            q.pop();
            
            for (int i = 0; i < 6; i++){
                
                int nz = z + dz[i];
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (inGrid(nz, nx, ny) && !v[nz][nx][ny] && A[nz][nx][ny] != '#'){
                    v[nz][nx][ny] = 1;
                    d[nz][nx][ny] = d[z][x][y] + 1;
                    q.push({nz, nx, ny});
                }
            }
        }
        
        if (d[ez][ex][ey] != 0) cout << "Escaped in " << d[ez][ex][ey] << " minute(s).\n";
        else cout << "Trapped!\n";
        
        cin >> l >> r >> c;
    }
}