#include <bits/stdc++.h>
using namespace std;

int k, n, m;
int path[200][200][31];
int grid[200][200];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int dkx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dky[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
    
    cin >> k >> m >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    
    memset(path, -1, sizeof(path));
    
    path[0][0][0] = 0;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while(!q.empty()){
        
        int a, b, c;
        tie(a, b, c) = q.front();
        q.pop();
        
        if (a == n-1 && b == m-1){
            cout << path[a][b][c];
            return 0;
        }
        
        for(int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if (inGrid(na, nb) && path[na][nb][c] == -1 && grid[na][nb] == 0){
                path[na][nb][c] = path[a][b][c] + 1;
                q.push({na, nb, c});
            }
        }
        
        if (c != k){
            for(int i = 0; i < 8; i++){
                int na = a + dkx[i];
                int nb = b + dky[i];
                
                if (inGrid(na, nb) && path[na][nb][c+1] == -1 && grid[na][nb] == 0){
                    path[na][nb][c+1] = path[a][b][c] + 1;
                    q.push({na, nb, c + 1});
                }
            }
        }
        
    }
    cout << -1;
}