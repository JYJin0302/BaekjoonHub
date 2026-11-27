#include <bits/stdc++.h>
using namespace std;

int w, h;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool inGrid(int x, int y){
    return x >= 0 && x < w && y >= 0 && y < h;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> w >> h;
    
    vector<string> A(w);
    for(auto& i : A) cin >> i;
    
    int dist[501][501];
    bool nextWall[501][501];
    
    int sx, sy, ex, ey;
    for(int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            // 점 찾기
            if (A[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (A[i][j] == 'E'){
                ex = i, ey = j;
            }
            
            // 벽타기 가능한지 확인
            bool ok = 0;
            for (int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (inGrid(ni, nj) && A[ni][nj] == '#') ok = 1;
            }
            nextWall[i][j] = ok;
            
            // init
            dist[i][j] = -1;
        }
    }
    
    deque<tuple<int, int, int>> q;
    q.push_back({sx, sy, 0});
    while(!q.empty()){
        
        int cx, cy, v;
        tie(cx, cy, v) = q.front();
        q.pop_front();
        
        if (dist[cx][cy] != -1) continue;
        dist[cx][cy] = v;
        
        for (int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (inGrid(nx, ny) && dist[nx][ny] == -1 && A[nx][ny] != '#'){
                bool wall = (nextWall[cx][cy] && nextWall[nx][ny]);
                
                if (wall) {
                    q.push_front({nx, ny, v});
                }
                else{
                    q.push_back({nx, ny, v+1});
                }
            }
        }
    }
    
    cout << dist[ex][ey];
}