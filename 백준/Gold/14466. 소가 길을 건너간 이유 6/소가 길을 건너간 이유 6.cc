#include <bits/stdc++.h>
using namespace std;

int n, k, r;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int cnt = 0;

int grid[101][101];
map<pair<int, int>, bool> path;

bool inGrid(int x, int y){
    return x > 0 && x <= n && y > 0 && y <= n;
}
void bfs(int x, int y){
    
    queue<pair<int ,int>> q;
    q.push({x, y});
    while(!q.empty()){
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        
        grid[a][b] = cnt;
        
        for (int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if (inGrid(na, nb) && !path[{a*n+b, na*n+nb}] && grid[na][nb] == 0){
                grid[na][nb] = cnt;
                q.push({na, nb});
            }
        }
    }
}

int main(){
   ios::sync_with_stdio(false);
cin.tie(nullptr); 
    cin >> n >> k >> r;
    
    for (int i =0 ; i < r; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        path[{a*n+b, c*n+d}] = 1;
        path[{c*n+d, a*n+b}] = 1;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 0){
                cnt++;
                bfs(i, j);
            }
        }
    }
    
    int tot = 0;
    vector<int> ans(cnt+1);
    int res = 0;
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        
        res += tot - ans[grid[a][b]];
        ans[grid[a][b]]++;
        tot++;
    }
    cout << res;
}