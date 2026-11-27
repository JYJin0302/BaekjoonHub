#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)

vector<int> root;
int find(int n){
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}

int n, m;
int grid[10][10];
int island[10][10];

vector<tuple<int, int, int>> edge;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y, int c){
    
    queue<pair<int, int>> q;
    q.push({x, y});
    island[x][y] = c;
    
    while(!q.empty()){
        
        int a, b;
        tie(a,b) = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if(inGrid(na, nb) && grid[na][nb] == 1 && island[na][nb] == 0){
                island[na][nb] = c;
                q.push({na, nb});
            }
        }
    }    
}

void search(int x, int y){
    
    if (grid[x][y] == 0) return;
    
    int c = island[x][y];
    
    FOR(i, 0, 4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        int cnt = 0;
        while(inGrid(nx, ny) && grid[nx][ny] == 0) nx += dx[i], ny += dy[i], cnt++;
        if (inGrid(nx, ny) && cnt >= 2){
            int nc = island[nx][ny];
            if (c != nc) edge.push_back({cnt, c, nc});
        }
    }
}


int main(){
    
    
    cin >> n >> m;
    
    FOR(i, 0, n) FOR(j, 0, m) cin >> grid[i][j];
    
    int icnt = 0;    
    FOR(i, 0, n) FOR(j, 0, m){
        if (grid[i][j] == 1 && island[i][j] == 0){
            icnt++;
            bfs(i, j, icnt);
        }
    }
    
    FOR(i, 0, n) FOR(j, 0, m) search(i, j);
    
    sort(edge.begin(), edge.end());
    
    root = vector<int>(icnt+1);
    FOR(i, 0, icnt+1) root[i] = i;
    
    int mcnt = 0, ans = 0;
    for (auto i : edge){
        
        
        int c, x, y;
        tie(c, x, y) = i;
        
        find(x), find(y);
        if (root[x] != root[y]){
            mcnt++;
            ans += c;
            root[root[x]] = root[y];
        }
    }
    
    if (mcnt == icnt-1) cout << ans;
    else cout << -1;
    
}