#include <bits/stdc++.h>
using namespace std;

int n, m;
struct P{
    int x, y;
};

vector<P> adj[101][101];

bool v[101][101];
bool L[101][101];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool inGrid(int x, int y){
    return x > 0 && x <= n && y > 0 && y <= n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    while(m--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a][b].push_back({c, d});
    }
    
    L[1][1] = 1;
    queue<P> q;
    q.push({1, 1});
    while(!q.empty()){
        
        P a = q.front();
        q.pop();
        if (v[a.x][a.y]) continue;
        v[a.x][a.y] = 1;
        
        for (P& k : adj[a.x][a.y]){
            if (!L[k.x][k.y]){
                L[k.x][k.y] = 1;
                bool ok = 0;
                for (int i = 0; i < 4; i++){
                    int tx = k.x + dx[i];
                    int ty = k.y + dy[i];
                    
                    if (inGrid(tx, ty) && v[tx][ty] == 1) ok = 1;
                }
                if (ok) q.push(k);
            }
        }
        
        for (int i = 0; i < 4; i++){
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];
            
            if (inGrid(nx,ny) && L[nx][ny] && !v[nx][ny]){
                q.push({nx, ny});
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            ans += L[i][j];
        }
    }
    cout << ans;
    
}