#include <bits/stdc++.h>
using namespace std;
#define INF 100000

int A[52][52][2];  // x, y, 0 : 가로, 1: 세로
vector<string> grid;

bool is0[52][52];
bool is1[52][52];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isturn(int x, int y){
    return is0[x-1][y] && is0[x][y] && is0[x+1][y];
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    string s( n+2, '1');
    grid = vector<string>(n+2, s);
    for (int i = 1; i <= n; i++){
        string ts;
        cin >> ts;
        
        grid[i] = '1' + ts + '1';
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            A[i][j][0] = A[i][j][1] = INF;
        }
    }
    
    int sx, sy, st;
    int vx, vy, vt;
    
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            
            if (grid[i][j] == 'B'){
                if (c1 == 1) sx = i, sy = j;
                else if (c1 == 2){
                    if (sy == j) st = 1;
                    else st = 0;
                }
                c1++;
                grid[i][j] = '0';
            }
            else if (grid[i][j] == 'E'){
                if (c2 == 1) vx = i, vy = j;
                else if (c2 == 2){
                    if (vy == j) vt = 1;
                    else vt = 0;
                }
                c2++;
                grid[i][j] = '0';
            }
            
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            
            if (grid[i-1][j] == '1' || grid[i][j] == '1' || grid[i+1][j] == '1') is1[i][j] = 0;
            else is1[i][j] = 1;
            
            if (grid[i][j-1] == '1' || grid[i][j] == '1' || grid[i][j+1] == '1') is0[i][j] = 0;
            else is0[i][j] = 1;
            
        }
    }
    
    A[sx][sy][st] = 0;
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, st});
    while(!q.empty()){
        
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (A[nx][ny][t] == INF){
                if (t == 1 && is1[nx][ny]) {
                    A[nx][ny][t] = A[x][y][t] + 1;
                    q.push({nx, ny, t});
                }
                
                if (t == 0 && is0[nx][ny]){
                    A[nx][ny][t] = A[x][y][t] + 1;
                    q.push({nx, ny,t});
                }
            }
        }
        
        int nt = 1 - t;
        if (A[x][y][nt] == INF && isturn(x, y)){
            A[x][y][nt] = A[x][y][t] + 1;
            q.push({x, y, nt});
        }
        
    }
    
    if (A[vx][vy][vt] == INF) A[vx][vy][vt] = 0;
    cout << A[vx][vy][vt];
    

}