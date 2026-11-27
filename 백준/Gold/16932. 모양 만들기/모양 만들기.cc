#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[1001][1001];
int Num[1001][1001];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    vector<int> B;
    B.push_back(0);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (A[i][j] == 1 && Num[i][j] == 0){
                
                queue<pair<int, int>> q;
                q.push({i, j});
                cnt++;
                Num[i][j] = cnt;
                
                int res = 0;
                while(!q.empty()){
                    
                    int a, b;
                    tie(a, b) = q.front();
                    q.pop();
                    res++;
                    for(int k = 0; k < 4; k++){
                        int na = a + dx[k];
                        int nb = b + dy[k];
                        
                        if (inGrid(na, nb) && A[na][nb] == 1 && Num[na][nb] == 0){
                            Num[na][nb] = cnt;
                            q.push({na, nb});
                        }
                    }
                }
                
                B.push_back(res);
                ans = max(ans, res);
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if (A[i][j] == 1) continue;
            
            int res = 1;
            for (int ti = 0; ti < 4; ti++){
                
                int ni = i + dx[ti];
                int nj = j + dy[ti];
                
                bool ok = 1;
                if (!inGrid(ni, nj)) ok = 0;
                
                for (int tj = 0; tj < ti; tj++){
                    int ii = i + dx[tj];
                    int jj = j + dy[tj];
                    
                    if (inGrid(ii, jj) && Num[ni][nj] == Num[ii][jj]) ok = 0;
                }
                
                if (ok) res += B[Num[ni][nj]];
            }
            
            ans = max(ans, res);
        }
    }
    
    cout << ans;
    
}