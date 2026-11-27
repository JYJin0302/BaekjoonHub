#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool grid[101][101];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

bool inGrid(int x, int y){
    return x > 0 && x <= n && y> 0 && y <= m;
}

int main(){
    
    cin >> m >> n >> k;
    
    for (int i = 0; i < k; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        
        x++, y++;
        for (int tx = x; tx <= a; tx++){
            for (int ty = y; ty <= b; ty++){
                grid[tx][ty] = 1;
            }
        }
    }
    
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!grid[i][j]){
                cnt++;
                int size = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = 1;
                while(!q.empty()){
                    int a, b;
                    tie(a, b)= q.front();
                    q.pop();
                    size++;
                    for (int k = 0; k < 4; k++){
                        int na = a+dx[k];
                        int nb = b + dy[k];
                        if (inGrid(na, nb) && !grid[na][nb]){
                            grid[na][nb] = 1;
                            q.push({na, nb});
                        }
                    }
                }
                ans.push_back(size);
            }
            
        }
    }
    
    cout << cnt << '\n';
    sort(ans.begin(), ans.end());
    for(int i : ans) cout << i << ' ';
    
}