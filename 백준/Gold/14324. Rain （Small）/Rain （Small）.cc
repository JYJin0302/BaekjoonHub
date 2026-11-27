#include <bits/stdc++.h>
using namespace std;

int r, c;
int grid[11][11];
bool f[11][11]; // finished

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inGrid(int x, int y){
    return x > 0 && x <= r && y > 0 && y <= c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int case_cnt = 1; case_cnt <= t; case_cnt++){
        
        cin >> r >> c;
        
        priority_queue<tuple<int, int, int>> pq;
        
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++){
                cin >> grid[i][j];
                f[i][j] = 0;
                bool b1 = (i == 1 || i == r);
                bool b2 = (j == 1 || j == c);
                
                if (b1 || b2) {
                    f[i][j] = 1;
                    pq.push({-grid[i][j], i, j});
                }
            }
        }
        
        int ans = 0;
        
        while(!pq.empty()){
            
            int a, b, c;
            tie(a, b, c) = pq.top();
            pq.pop();
            
            for (int i = 0; i <4; i++){
                int nb = b + dx[i];
                int nc = c + dy[i];
                
                if (inGrid(nb ,nc) && !f[nb][nc]){
                    f[nb][nc] = 1;
                    if (grid[nb][nc] <= grid[b][c]){
                        ans += grid[b][c] - grid[nb][nc];
                        grid[nb][nc] = grid[b][c];
                    }
                    pq.push({-grid[nb][nc], nb, nc});
                }
            }
        }
        
        cout << "Case #" << case_cnt << ": " << ans << '\n';
    }
}