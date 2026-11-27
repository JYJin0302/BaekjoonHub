#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
vector<string> grid;

int L[701][701], R[701][701], U[701][701], D[701][701];
bool used_C[701][701], used_R[701][701];

int dist[701][701];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    grid = vector<string>(n);
    for(auto& i : grid) cin >> i;
    
    int vx, vy, sx, sy, tx, ty;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m ;j++){
            if (grid[i][j] == 'V'){
                vx = i, vy = j;
            }
            else if (grid[i][j] == 'Y'){
                sx = i, sy = j;
            }
            else if (grid[i][j] == 'T'){
                tx = i, ty = j;
            }
        }
    }
    
    // fill L, R, U, D
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] != 'I'){
                if (j == 0 || grid[i][j-1] == 'I') L[i][j] = j;
                else L[i][j] = L[i][j-1];
                
                if (i == 0 || grid[i-1][j] == 'I') U[i][j] = i;
                else U[i][j] = U[i-1][j];
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        for (int j = m-1; j >= 0; j--){
            if (grid[i][j] != 'I'){
                if (j == m-1 || grid[i][j+1] == 'I') R[i][j] = j;
                else R[i][j] = R[i][j+1];
                
                if (i == n-1 || grid[i+1][j] == 'I') D[i][j] = i;
                else D[i][j] = D[i+1][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            dist[i][j] = 1000000;
        }
    }
    int visited[701][701];
    memset(visited, -1, sizeof(visited));
    visited[vx][vy] = 0;
    
    queue<pair<int, int>> q;
    q.push({vx, vy});
    while(!q.empty()){
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        
        // u d
        int ta = U[a][b], tb = D[a][b];
        if (!used_C[ta][b]){
            used_C[ta][b] = 1;
            for (int i =ta; i <= tb; i++) dist[i][b] = min(dist[i][b], visited[a][b]);
        }
        // l r
        ta = L[a][b], tb = R[a][b];
        if (!used_R[a][ta]){
            used_R[a][ta] = 1;
            for (int i = ta; i <= tb; i++) dist[a][i] = min(dist[a][i], visited[a][b]);
        }
        
        for (int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if (inGrid(na, nb) && visited[na][nb] == -1 && grid[na][nb] != 'I'){
                visited[na][nb] = visited[a][b] + 1;
                q.push({na, nb});
            }
        }
    }
    
    int vis[701][701];
    memset(vis, -1, sizeof(vis));
    vis[sx][sy] = 0;
    q.push({sx, sy});
    while(!q.empty()){
        int a, b;
        tie(a,b) = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if (inGrid(na, nb) && grid[na][nb] != 'I' && vis[na][nb] == -1 && dist[na][nb] > vis[a][b] + 1){
                vis[na][nb] = vis[a][b] + 1;
                q.push({na, nb});
            }
        }
    }
    
    if (vis[tx][ty] != -1) cout << "YES";
    else cout << "NO";
}
