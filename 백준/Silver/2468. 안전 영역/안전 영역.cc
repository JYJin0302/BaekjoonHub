#include <bits/stdc++.h>
using namespace std;

int n;
int grid[100][100];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
vector<vector<bool>> visited;

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y, int h){
    
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if(inGrid(na, nb) && !visited[na][nb] && grid[na][nb] > h){
                visited[na][nb] = 1;
                q.push({na, nb});
            }
        }
    }
}

int test(int h){
    
    int cnt = 0;
    visited = vector<vector<bool>> (n, vector<bool>(n));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (!visited[i][j] && grid[i][j] > h) cnt++, bfs(i, j, h);
        }
    }
    
    
    return cnt;
}

int main(){
    
    cin >> n;
    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    
    int ans = 1;
    for(int i = 1; i <= 100; i++){
        ans = max(ans, test(i));
        
    }
    
    cout << ans;
    
}