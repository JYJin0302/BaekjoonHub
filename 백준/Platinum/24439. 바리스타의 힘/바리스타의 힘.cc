#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {-1, 0 ,1 ,0};
int dy[] = {0, 1, 0, -1};

const int INF = 1e7;

string grid[1001];

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int fr[1001][1001];
int bk[1001][1001];

int row[1001];
int col[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    
    // init
    for (int i= 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fr[i][j] = INF;
            bk[i][j] = INF;
        }
    }
    
    // bfs from front
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    fr[0][0] = 0;
    while(!q.empty()){
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if (inGrid(na, nb) && grid[na][nb] == '0' && fr[na][nb] == INF){
                fr[na][nb] = fr[a][b] + 1;
                q.push({na, nb});
            }
        }        
    }
    
    // bfs from back
    q.push({n-1, m-1});
    bk[n-1][m-1] = 0;
    while(!q.empty()){
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        
        if (grid[a][b] == '1') continue;
        
        for (int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if (inGrid(na, nb) && bk[na][nb] == INF){
                bk[na][nb] = bk[a][b] + 1;
                q.push({na, nb});
            }
        } 
    }
    
    int ans = INF;
    int tmp[1001][1001];
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0) tmp[i][j] = fr[i][j];
            else tmp[i][j] = min(fr[i][j], tmp[i-1][j]+1);
            
            ans = min(ans, tmp[i][j] + bk[i][j]);
        }
    }
    
    for (int j = 0; j < m; j++){
        for (int i = 0;i < n; i++){
            if (j == 0) tmp[i][j] = fr[i][j];
            else tmp[i][j] = min(fr[i][j], tmp[i][j-1] + 1);
            
            ans = min(ans, tmp[i][j] + bk[i][j]);
        }
    }
    
    if (ans == INF) ans = -1;
    cout << ans;
}