#include <bits/stdc++.h>
using namespace std;

int r, c;
int grid[51][51];
bool f[51][51]; // finished

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inGrid(int x, int y){
    return x > 0 && x <= r && y > 0 && y <= c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> r >> c;
        
    priority_queue<tuple<int, int, int>> pq;
        
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            char cc;
            cin >> cc;
            grid[i][j] = cc - '0';
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
            
        int a, b, d;
        tie(a, b, d) = pq.top();
        pq.pop();
            
        for (int i = 0; i <4; i++){
            int nb = b + dx[i];
            int nd = d + dy[i];
                
            if (inGrid(nb ,nd) && !f[nb][nd]){
                f[nb][nd] = 1;
                if (grid[nb][nd] <= grid[b][d]){
                    ans += grid[b][d] - grid[nb][nd];
                    grid[nb][nd] = grid[b][d];
                }
                pq.push({-grid[nb][nd], nb, nd});
            }
        }
    }
        
    cout << ans;
}